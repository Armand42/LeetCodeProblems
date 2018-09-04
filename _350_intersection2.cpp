#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> mymap;
        for(int i = 0; i < nums1.size(); i++) {
            if (mymap.find(nums1[i]) != mymap.end()) {  // if in map increase frequency of element by 1
                mymap[nums1[i]] += 1;
            }
            else {
                mymap[nums1[i]] = 1;    // first time seeing one
            }
        
        }
        for (int i = 0; i < nums2.size(); i++) {
            if(mymap.find(nums2[i]) != mymap.end() && mymap[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                mymap[nums2[i]] -= 1;       // must decrement frequency because arrays could be different sizes   
            }
        }
         // nums1 = [1,2,3]
         // nums2 = [1, 2, 1]
         
         // key of nums1
         // mymap: 1->1
         //        2->1
         //        3->1
         //     key -> frequency
        
         // looped through nums2 and decrement frequency if the number was in the map and the frequency is > 0
         // pushed keys into result
         //

        // nums2 = [1,1,1,1,1,1,1,1,1,1,1]
        //  result: 1 1 1 1
        // expected answer: [1,1,1,1,1,1,1,1,1,1,1]
        // myset: (1)
        // result: [1,1]
        
        return result;
    }
    
};




int main() {
  vector<int> test;
  vector<int> test2;
    test.push_back(6);
    test.push_back(5);
    test.push_back(3);
    test2.push_back(6);
    test2.push_back(5);
    test2.push_back(3);
    Solution sol;
    sol.intersect(test,test2);


    return 0;
}