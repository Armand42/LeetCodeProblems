#include <iostream>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 1 -> 2 ->3
    //     1
    //   /    \
    //   2    3
    //  /  \
    //  4    5
    //        \
    //         6
    // longest path: 1->2->5->6 (4 nodes) -> depth = 4
    // root->val = 1
    // root->left = node 2, root->left->val = 2;
    // root->right = node 3, root->right->val = 3;
    // root->left->left = Node 4 (pointer to node 4)
    // root->left->right = pointer to node 5
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = maxDepth(root->left); // depth of left side
        int right = maxDepth(root->right);
        return 1 + std::max(left, right);// 1 for the root, choose the longer one for left or right
    }
};
int main() {
    return 0;
}