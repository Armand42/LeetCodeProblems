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
    //   4
    // 2   5
//   1  3 6
// Tilt: 
// 1: 0
// 3: 0
// 2: 3-1 = 2
// 6: 0
// 5: 6
// 4: (5+6) - (1+2+3) = 11 - 6 = 5
// tilt: 2 + 6 + 5 = 13
    int tilt = 0;
    int findTilt(TreeNode* root) {
        
        //int sum1 = 0;
        //int sum2 = 0;
        if (root == NULL) return 0; // O(1)
        traverse(root); // find sum of all nodes 
        return tilt;
    }
    int traverse(TreeNode* root) { // assume the running time of traverse function is T(N)
        if (root == NULL) return 0; // O(1)
        int left = traverse(root->left); // T(Nleft)
        int right = traverse(root->right); // recursively traverse the right T(Nright)
        tilt += abs(left-right); // O(1)
        return left + right + root->val; // O(1)
    }
    // T(N) = O(1) + T(Nleft) + T(Nright) = O(N)
};




int main() {
    return 0;
}