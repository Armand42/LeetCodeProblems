#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#define INF 100000000

using namespace std;

class Solution {
public:
  
class Solution {
public:
    
    // [2,2,1] -> return 2
    // [2,1,2,1,2,1,2] -> return 2
    // [1,2,3] return 1
    // [1] -> return 1
    // [-1,-1,-1,-1,-1,-2] return 2
    int thirdMax(vector<int>& nums) {
        // set -> binary search tree -> keys are unique and in increasing order;
        // [1,4,4,4,4,3,3,3,2,2]
        set<int> myset(nums.begin(), nums.end()); // remove duplicates and sort in increasing order
        // O(Nlog N) -> insert N number into myset (each take O(logN))
        // 1,2
        // myset.begin() --> point to smallest one (myset.end() is not the last one)
        // myset.rbegin() --> point to largest one
        // 1 2 3 4
        //   +2  +1  ^
        if (myset.size() < 3) return *myset.rbegin(); //O(log N) 
        
        myset.erase(*myset.rbegin()); // O(log N)
        myset.erase(*myset.rbegin()); // O(log N)
        // rbegin() + 2;--> not work
        // erase not work for reverse iterator, erase(val);
        return *(myset.rbegin()); // O(log N)
        // O(NlogN)
    }
    // sort the array and find the third maximum, (duplications) // 1 1 1 1 2 2 2 2 2 2
    int thirdMax2(vector<int>& nums) {
        int max = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        } // O(N)
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > secondMax && nums[i] != max) {
                secondMax = nums[i];
            }

        } // O(N)
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > thirdMax && nums[i] != secondMax && nums[i] != max) {
                thirdMax = nums[i];
            }
        }
        // O(N)
        //[1,2,-2147483648, 2, 0] --> return 0
        
        if (thirdMax != INT_MIN) return thirdMax;//good
        else{
            // thirdMax is INT_MIN
            // case 1: INT_MIN is in the array and it is the thirdMax return INT_MIN
            // case 3: INT_MIN is in the array and it is not the thirdMax return max
            // case 2: there is no thirdMax --> return max;
            for(int i = 0; i < nums.size(); i++) 
                if (nums[i] == INT_MIN && secondMax != INT_MIN) return INT_MIN; // return thirdMax
            return max; 
            // O(N)
        } // O(N)
        // time: O(N) + O(N) + O(N) + O(N) = O(4N) = O(N)
        // extra space: O(3) = O(1) space;
    }
};



int main() {
    Solution sol;
    int arr1[3] = {3,2,1};
    vector<int> result(arr1, arr1 + 3);
    cout << sol.thirdMax(result);
    return 0;
}