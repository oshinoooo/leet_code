#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> out;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 1});
        int level = 1;

        vector<int> tmp;
        while (!que.empty()) {
            auto node = que.front();
            que.pop();

            if (!node.first)
                continue;

            if (level != node.second) {
                out.push_back(tmp);
                ++level;
                tmp.clear();
            }

            tmp.push_back(node.first->val);

            que.push({node.first->left, level + 1});
            que.push({node.first->right, level + 1});
        }

        out.push_back(tmp);

        return out;
    }

    vector<vector<int>> levelOrder2(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> out;
        vector<int> tmp;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            out.push_back(tmp);
            tmp.clear();
        }

        return out;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            vector<int> tmp;
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = que.front();
                que.pop();

                if (!node)
                    continue;

                tmp.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            if (!tmp.empty())
                out.push_back(tmp);
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
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

    Solution s;
    vector<vector<int>> out = s.levelOrder(n1);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
