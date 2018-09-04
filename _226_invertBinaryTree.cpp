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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL; // O(1)
        TreeNode *temp = root->right; // O(1)
        root->right = invertTree(root->left); // T(Nleft)
        root->left = invertTree(temp);// T(Nright)

        return root; // O(1)
    }
    // T(N) = O(1) + T(Nleft) + T(Nright) = O(N)
};



int main() {
    return 0;
}