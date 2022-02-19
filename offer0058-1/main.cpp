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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        string out;
        int pre;
        bool start = false;

        for (int i = 0; i < n; ++i)
        {
            if (!start && s[i] != ' ')
            {
                start = true;
                pre = i - 1;
            }

            if (start && (s[i] == ' ' || i == n - 1))
            {
                if (s[i] == ' ')
                {
                    string tmp = s.substr(pre + 1, i - pre - 1);
                    if (!out.empty())
                        out = tmp + ' ' + out;
                    else
                        out = tmp;
                }
                else
                {
                    string tmp = s.substr(pre + 1, i - pre);
                    if (!out.empty())
                        out = tmp + ' ' + out;
                    else
                        out = tmp;
                }

                pre = i;
                start = false;
            }
        }
        return out;
    }
};

void DLR(TreeNode* root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    DLR(root->left);
    DLR(root->right);
}

int main_backup()
{
    // list
    cout << "--------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* n0;
    while (n0 != nullptr)
    {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;

    // tree
    cout << "--------------------" << endl;
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n2 = new TreeNode(2);
//    TreeNode* n3 = new TreeNode(3);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n5 = new TreeNode(5);
//    TreeNode* n6 = new TreeNode(6);
//    TreeNode* n7 = new TreeNode(7);
//
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;

    // show
    cout << "--------------------" << endl;
    vector<int> nums = {};
    vector<int> out;
    for (auto num : out)
        cout << num << " ";
    cout << endl;

//    vector<vector<int>> out;
//    for (auto ou : out)
//    {
//        for (auto o : ou)
//            cout << o << " ";
//        cout << endl;
//    }

    cout << "--------------------" << endl;
    return 0;
}

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.reverseWords("1 ") << endl;
    cout << "---------------------" << endl;
    return 0;
}