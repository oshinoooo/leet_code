#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

class TestThread {
public:
    void show() {
        lock_guard<mutex> lock(mux);
        cout << "Starting: " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Exiting : " << this_thread::get_id() << endl;
    }

private:
    mutex mux;
};

class TestYield {
public:
    TestYield() {
        ready = false;
    }

    void count(int id)
    {
        while (!ready)
            this_thread::yield();

        for ( int i = 0; i < 1000000; ++i) {}

        lock_guard<std::mutex> lock(mux);
        cout << "Thread: "<< id << endl;
    }

    void setReady() {
        ready = true;
    }

private:
    mutex mux;
    atomic<bool> ready;
};

class TestPrint{
public:
    TestPrint() : ptr(0), str("12345"), printCount(100) {}

    void show(int i) {
        while (0 < printCount) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return ptr % 5 == i || 0 == printCount;});
            if (printCount == 0)
                return;
            cout << "thread id: " << i << ", " << str[ptr] << ", count: " << printCount << endl;
            ptr = (ptr + 1) % 5;
            --printCount;
            cv.notify_all();
        }
    }

private:
    int ptr;
    const string str;
    int printCount;
    mutex m;
    condition_variable cv;
};

int test5() {
    cout << "----------------------------------------" << endl;
    TestPrint testPrint;

    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(thread(&TestPrint::show, &testPrint, i));

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();
    cout << "----------------------------------------" << endl;
    return 0;
}

int test1() {
    cout << "---------------------test1()" << endl;
    TestThread object;

    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(thread(&TestThread::show, &object));

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

    cout << "---------------------test1()" << endl;
    return 0;
}

int test2() {
    cout << "---------------------test2()" << endl;
    TestThread object;
    thread t = thread(&TestThread::show, &object);
    t.detach();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "---------------------test2()" << endl;
    return 0;
}

int test3() {
    cout << "---------------------test3()" << endl;
    TestYield object;

    vector<thread> threads;
    for (int i = 0; i < 10; ++i)
        threads.push_back(thread(&TestYield::count, &object, i));

    object.setReady();

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

    cout << "---------------------test3()" << endl;
    return 0;
}

class TestPool {
public:
    void serve() {
        unique_lock<mutex> lock(m);
        conditionVariable.wait(lock, [this](){return !buffer.empty();});
        string request = buffer.front();
        buffer.pop();
        lock.unlock();

        cout << this_thread::get_id() << ": " << request << endl;

        cout << this_thread::get_id() << ": starts to sleep" << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << this_thread::get_id() << ": wakes up" << endl;
        cout << "-------------------------------------------------" << endl;
    }

    void request(string str) {
        unique_lock<mutex> lock(m);
        buffer.push(str);
        conditionVariable.notify_all();
    }

private:
    mutex m;
    condition_variable conditionVariable;
    queue<string> buffer;
};

void test4() {
    TestPool testPool;

    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(thread(&TestPool::serve, &testPool));

    for (int i = 0; i < 10; ++i) {
        threads.push_back(thread(&TestPool::request, &testPool, string(50, i + '0')));
        this_thread::sleep_for(chrono::seconds(3));
    }

    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();
}

int main() {
    cout << "---------------------main()" << endl;
//    test1();
//    test2();
//    test3();
    test4();
    cout << "---------------------main()" << endl;
}
