class Solution {
public:
    // 1 1 2 3 4 5
    // [1, 6]
    // 3 6 1 2 2 4 ( from 1 to size)
    // myset: 3 6 1 2 4 
    // [2, 5]
    // find two numbers
    // duplicate one: two for loops 
    // 
    // missing one: we know array have all numbers from 1-6 but the missing
    // 1-->6 and check if that in the array: 1 yes, 2 yes, 3 yes, 4 yes, 5 no
    // for(i = 1; i <= size;  i++) { search for i in the array, if the array doesn't contain i, then i is the missing one}
    // unordered_set: find in O(1) time
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        
        unordered_set<int> myset2;
        
        // myset: 6 3 1 2 _
        // find (2) in my set:return an iterator if found, otherwise return myset.end()
//         for (int i = 0; i < nums.size(); i++) {
//             if (myset.find(nums[i]) == myset.end()) { // goes through end and doesn't find it
//                 myset.insert(nums[i]);
//             }
//             else {
//                 result.push_back(nums[i]);
//             }
//         } // O(n)
        
//         for (int missingKey = 1; missingKey <=nums.size(); missingKey++) {         // finding missing key
//             if (myset.find(missingKey) == myset.end()) { // goes through end and doesn't find it
//                 result.push_back(missingKey); // pushing missing key into result vector
//                 return result;
//             }
//         }
        
        
        vector<int> myset;
        // binary search tree: find O(log n)
        // 
        for (int i = 0; i < nums.size(); i++) {
            if (find(myset.begin(), myset.end(), nums[i]) == myset.end()) { // goes through end and doesn't find it
                myset.push_back(nums[i]);
            }
            else {
                result.push_back(nums[i]);
            }
        } // O(n log n)
        
        for (int missingKey = 1; missingKey <=nums.size(); missingKey++) {         // finding missing key
            if (find(myset.begin(), myset.end(), missingKey) == myset.end()) { // goes through end and doesn't find it
                result.push_back(missingKey); // pushing missing key into result vector
                return result;
            }
        } // O(nlogn)
        
        
    }
};
