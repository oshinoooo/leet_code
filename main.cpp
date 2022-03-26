#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

namespace myTemplate {
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

void showTree(TreeNode* root) {
    if (root == nullptr) return;
    showTree(root->left);
    cout << root->val << " ";
    showTree(root->right);
}

int main_backup() {
    // list
    cout << "--------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    ListNode* n0;
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;

    // tree
    cout << "--------------------" << endl;
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

    // show
    cout << "--------------------" << endl;
    vector<int> nums = {};
    vector<int> out;
    for (auto num : out)
        cout << num << " ";
    cout << endl;

    vector<vector<int>> nums = {};
    vector<vector<int>> outs;
    for (auto out : outs) {
        for (auto num : out)
            cout << num << " ";
        cout << endl;
    }

    cout << "--------------------" << endl;
    return 0;
}
}

class Solution {
public:

};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << "" << endl;
    cout << "--------------------" << endl;
    return 0;
}
