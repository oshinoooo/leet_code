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
    vector<vector<int>> pathSum(TreeNode* root, int target)
    {
        vector<vector<int>> out;
        vector<int> tmp;
        DFS(root, target, 0, tmp, out);
        return out;
    }

private:
    void DFS(TreeNode* root, int& target, int sum, vector<int>& tmp, vector<vector<int>>& out)
    {
        if (root == nullptr)
            return;

        tmp.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right)
        {
            if (target == sum)
                out.push_back(tmp);
        }
        else
        {
            DFS(root->left, target, sum, tmp, out);
            DFS(root->right, target, sum, tmp, out);
        }

        sum -= root->val;
        tmp.pop_back();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    vector<vector<int>> out = s.pathSum(n1, 7);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
