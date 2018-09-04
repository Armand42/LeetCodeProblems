#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // [1,2,2] -> false
    // [0,2,1] --> true
    // [1,3,3] -> false
    // [1,2,3,2] -> false
    
    // [1 2 2]
    // set: 1 2 
    bool containsDuplicate(vector<int>& nums) {
        //vector<int> result;
        unordered_set<int> myset;// hashtable O(1) for lookup
        //unordered_map<int,int> mymap;
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); i++) {
            // go throught the set and check for num[i], if num[i] contains in the set, then you return false, 
            // go to the end, return true
            if (myset.find(nums[i]) != myset.end()) { // goes through the end and finds it
              return false;
            }
            myset.insert(nums[i]);   
        }
        return true;
    }
};

int main() {
    vector<int> result;
    result.push_back(5);
    result.push_back(0);
    result.push_back(3);
    Solution sol;
    cout << sol.containsDuplicate(result);






    return 0;
}