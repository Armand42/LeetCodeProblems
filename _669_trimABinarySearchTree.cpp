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
//   3
// 1    4
// range [4,5]
// 4
    TreeNode* trimBST(TreeNode* root, int L, int R) { // T(N)
        if (root == NULL) return NULL; // O(1)
        if (root->val < L) return trimBST(root->right,L,R); //T(Nright)
        if (root->val > R) return trimBST(root->left,L,R);   // T(Nleft)
        // every thing on the left <= root->val (binary search tree) 

        // root->left might be NULL, NULL->val gives runtime error

        root->left = trimBST(root->left,L,R); // T(Nleft)
        root->right = trimBST(root->right,L,R); // T(Nright)
        
        return root;
    }
    // T(N) = O(1) + T(Nleft) + T(Nright) 
// T(N) = O(N)
//       4
//    2     6
//  1   3  5   7
// 0
// T(8) = 1 + T(4) + T(3) = 1 + 4 + 3 = 8
// T(4) = 1 + T(2) + T(1)  = 1 + 2 + 1 = 4
// T(3) = 3
// claim : T(N) = N
};







int main() {
    return 0;
}