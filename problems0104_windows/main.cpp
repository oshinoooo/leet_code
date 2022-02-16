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
#include <ctime>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth1(TreeNode* root) {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepth(TreeNode* root) {
        int out = 0;

        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 1});

        while (!stk.empty()) {
            auto [node, curDepth] = stk.top();
            stk.pop();

            while (node) {
                out = max(out, curDepth);
                ++curDepth;
                stk.push({node->right, curDepth});
                node = node->left;
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
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

    Solution s;
    cout << s.maxDepth(n1) << endl;
    cout << "---------------------" << endl;
    return 0;
}
