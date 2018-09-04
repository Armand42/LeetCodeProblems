#include <iostream>
using namespace std;



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL) return 1+minDepth(root->right);
        if (root->right == NULL) return 1+minDepth(root->left);

        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return 1 + min(left,right);
        //    2
        //  3    4
        // 1 2  3   5
    }
    // visit the root, visit the left tree to find minDepth of left, visit the right tree to find minDepth of right
    // every node got visited once -> O(N) where N is total number of nodes
};
// T(N) = O(1) + T(N/2) + T(N/2) = 2T(N/2) + 1
// master theorem -> O(N)



int main() {
    return 0;
}