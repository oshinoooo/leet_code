#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        int flag = 0x1;

        while (n > 0)
        {
            count += n & flag;
            n = n >> 1;
        }

        return count;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.hammingWeight(11) << endl;
    cout << "---------------------" << endl;
    return 0;
}
