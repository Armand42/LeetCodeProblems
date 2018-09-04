#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// [1,2,3,4,5,0,0,0]
// [0,0,0,1,2,3,4,5]
// nums2 = [1, 2, 1]
         
         // key of nums1
         // mymap: 1->1
         //        2->1
         //        3->1
         //     key -> frequency


// array [2,0,3,1,0,4,7,0,6,0,2]
// pos: 6
// array [2,3,1,4,7,6,2,0,0,0,0]
// pos increments by 1 everytime != zero
// pos tells you how many nonzeros
// at the end assign whatever is nonzero to zero
class Solution {
public:
// don't use any extra space
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos] = nums[i];    // assigns position number so zero can be replaced
                pos++;                  // increment position in order to move onto next replacement
            }
        }
        for (int i = pos; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};



int main() {
    Solution sol;
    int arr1[7] = {1,0,3,7,5,5,0};
    vector<int> result(arr1, arr1 + 5);
    
    sol.moveZeroes(result);
    
    return 0;
}