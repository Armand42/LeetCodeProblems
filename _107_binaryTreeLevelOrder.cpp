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
    // 2    5
//  1   3  6   
// 0  7
    
// result: [[4], [2,5],[1,3,6],[0,7]]
// queue: []
// [[4],[2,5],[1,3, 6],[0,7]]

    vector<vector<int>> levelOrderBottom(TreeNode* root) { 
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        // breath first search traverse order
        while (!myqueue.empty()) {
            int n = myqueue.size();
            vector<int> row;
            for(int i = 0; i < n; i++){
                TreeNode* current = myqueue.front();
                row.push_back(current->val);
                myqueue.pop();
                if (current->left != NULL) myqueue.push(current->left);
                if (current->right != NULL) myqueue.push(current->right);   
            }
            result.push_back(row);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// [9, 20, 15, 7]
//[3]
// [9, 20]
// [15,7]
// breath first search algorithm (graph algorithm)
// start from source (root) 






int main() {
    return 0;
}