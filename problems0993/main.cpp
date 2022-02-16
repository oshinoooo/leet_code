#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <tuple>

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
    bool isCousins(TreeNode* root, int x, int y)
    {

    }

    void DFS(TreeNode* root)
    {
        stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode* tmp = nodes.top();
            nodes.pop();

            while (tmp != nullptr)
            {
                cout << tmp->val << " ";
                nodes.push(tmp->right);
                tmp = tmp->left;
            }
        }
        cout << endl;
    }

    int depth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        return max(depth(root->left) + 1, depth(root->right) + 1);
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
//    n1->right = n3;
//    n2->left = n4;
    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;

    cout << s.isCousins(n1, 5, 6) << endl;
    s.DFS(n1);
    cout << s.depth(n1) << endl;
    cout << "---------------------" << endl;
    return 0;
}
