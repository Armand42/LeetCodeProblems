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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        inorder(root);
        return sum;
    }
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL) { // if root has left subtree - root changes after every recursive step
            if (root->left->left == NULL && root->left->right == NULL)  // if the left of the root is a leaf
                sum += root->left->val;
            else // if the left is not a leaf
                inorder(root->left); // recursively traverse the left subtree
        }
        inorder(root->right); // recursively traverse the right
    }
    //    2
    //  3     4
    // 1  7  5  6
  //-1 -2
    // left leaves: 1,5
    // should return 6
    //  order visited: 
    // current: 3   

// recursive stack (FILO)

//
// 
//  inorder(1)
//  inorder(3)
//  inorder(2)
        
    }
};





int main() {
    return 0;
}