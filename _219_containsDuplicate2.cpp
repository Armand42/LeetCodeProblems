#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

// [1 2 3 1 2 1]
//  0 1 2 3 4 5
// k = 2
// return true,
// for i = 0 to i = 5
// i=0: check if 1 is in the map
// map: 1 -> 0
// i=1: check if 2 is in the map
// map: 1->0
//      2->1
// i=2: check if 3 is in the map
// map: 1->0
//      2->1
//      3->2
// i=3: check if 1 is in the map, yes, 3 - 0 <= 2, no
// map: 1->3
//      2->1
//      3->2
// 
// i=4: check if 2 is in the map, yes, 4 - 1 <= 2, no
// map: 1->3
//      2->4
//      3->2
// 
 // i=5: check if 1 is in the map, yes, 5 - 3 <= 2, yes
// map: 1->3
//      2->4
//      3->2
// 
class Solution {
public:
// [1 2 3 1 2 1]
// k = 2
// return true, 
// map: 1 -> 5
//      2 -> 1
//      3 -> 2

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for (int i = 0; i < nums.size(); i++) {
            if (mymap.find(nums[i]) != mymap.end() && i-mymap[nums[i]] <= k) {
                return true;
            }
            mymap[nums[i]] = i;
        }
        
    }
    return false;

};

int main() {
    vector<int> result;
    result.push_back(6);
    result.push_back(5);
    result.push_back(3);
    Solution sol;
    sol.containsNearbyDuplicate(result);


    return 0; 
}
