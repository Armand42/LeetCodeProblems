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
    bool isBalanced(TreeNode* root) {
           return findDepth(root) != -1;
        }
    
    // findDepth return the depth of the root but only if it is balanced
    // otherwise I return -1
    // -1 is not balanced;
    int findDepth(TreeNode *root){ // T(N)
        if (root == NULL) return 0;             // O(1)
        int left = findDepth(root->left);       // T(N1)
        int right = findDepth(root->right);     // T(N2)

        if (left == -1 || right == -1) return -1; // O(1)
        if (abs(left-right) <= 1) return 1 + max(left, right); // O(1)
        else return -1; // O(1)
    }
};  // T(N) = O(1) + T(N1) + T(N2) -> solve recursion you get T(N) = O(N)

// left = 1, right = 3  -> abs(1-3) = 2 > 1 -> not balanced
// left = 2, right = 1 -> abs(2-1) = 1 <= 1 -> balanced
// left = 1, right = 5 -> abs(left-right) = 4 > 1


void preOrder(TreeNode *root) {
    if (root == NULL) return;
    cout << root->val << endl;
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(TreeNode *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->val << endl;
    inOrder(root->right);
}
void postOrder(TreeNode *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << endl;
}

int main() {
    //  3
    // 2  1
    //4 5
    // preorder: 3 2 4 5 1
    // inorder: 4 2 5 3 1
    // postorder: 4 5 2 1 3
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    //root->left->left->left = new TreeNode(6);
    //cout << sol.isBalanced(root) << endl;
    cout << "PreOrder: " << endl;
    preOrder(root);
    cout << "InOrder: " << endl;
    inOrder(root);
    cout << "PostOrder: " << endl;
    postOrder(root);
    return 0;
    //       3
    //    2     1
    //  5  4       7
    //       6
    // preorder: 3 2 5 4 6 1 7
    // inorder: 5 2 4 6 3 1 7
    // postorder: 5 6 4 2 7 1 3
}