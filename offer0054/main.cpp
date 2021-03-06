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
    int kthLargest(TreeNode* root, int k)
    {
        vector<int> store;
        RDL(root, k, store);
        return store.back();
    }

private:
    void RDL(TreeNode* root, int k, vector<int>& store)
    {
        if (root == nullptr)
            return;
        RDL(root->right, k, store);
        if (store.size() == k)
            return;
        store.push_back(root->val);
        RDL(root->left, k, store);
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    cout << s.kthLargest(n1, 5) << endl;
    cout << "---------------------" << endl;
    return 0;
}
