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
// t1: 4
// t2:  
//   2
//  1  3
// merge(t1, t2) 
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {// T(N1, N2)
        if (t1 == NULL) return t2; // O(1)
        if (t2 == NULL) return t1; // O(1)
        TreeNode *tree = new TreeNode(t1->val + t2->val); // O(1)
        // make a pointer point to that new node (sum of t1 and t2)
        tree->left = mergeTrees(t1->left, t2->left);    // T(N1left, N2left)
        tree->right = mergeTrees(t1->right, t2->right);  // T(N1right, N2left)
        return tree;
    }// O(N1+N2)
};




int main() {
    return 0;
}