#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return myIsSymmetric(root, root);
    }

private:
    bool myIsSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;

        if (!left || !right || left->val != right->val)
            return false;

        return myIsSymmetric(left->left, right->right) && myIsSymmetric(left->right, right->left);
    }
};

int main() {
    cout << "--------------------" << endl;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(2);
    TreeNode* n4 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(3);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution s;
    cout << s.isSymmetric(n1) << endl;
    cout << "--------------------" << endl;
    return 0;
}103685
