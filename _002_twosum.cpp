#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
                //cout << i << ' ' << j << endl;
            }
        }
        // O(n^2)
        return result;
    }

    // 5 12 1 19    target 6
    // [0, 2]
    // (5, 0)
    // search for target - num[i]

    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++){ // O(n)
            if (mymap.find(target-nums[i]) != mymap.end()){ // O(1)
                result.push_back(mymap[target-nums[i]]);
                result.push_back(i);
                return result;
            } 
            else {
                mymap[nums[i]] = i;
            }
            // O(1)
        }
        return result;
    }
        
}






};

void print(vector<int> & a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main(){
    Solution * sol = new Solution();

    int a[5] = {1,4,7,8,10};
    vector<int> nums(a , a+5);
    vector<int> result = sol->twoSum(nums, 18);
    print(result);
    
    return 0;
}