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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true; 
        if (p == NULL && q != NULL) return false;
        if (p != NULL && q == NULL) return false; // base cases
        if (p->val != q->val) return false;
        bool sameleft = isSameTree(p->left,q->left);
        bool sameright = isSameTree(p->right, q->right); 
        return  sameleft && sameright;
        }
        // O(size(p) + size(q)) = O(N) where N the number of nodes in the bigger one
    //  1
    // 2  3
    
    //  1
    // 2  4
    }
};





int main() {
    return 0;
}