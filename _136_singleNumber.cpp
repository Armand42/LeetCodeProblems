class Solution {
public:
    // XOR function and bit manupilation 
    //nums = [1,2, 4, 1, 3,4,2]
    // return 3
    // two for loops, for each number, do 1 for loop to count how many times it appear, if it is 1, return that number O(n^2)
    // unordered_set: 
    // keep track the unique element (don't care about the order)
    // don't have information for the number of times it appears
    // myset (1, 2, 4, 3)
    //nums = [1,2, 4, 1, 3,4,2]
    // 1 -> 2
    // 2 -> 2
    // 4 -> 2
    // 3 -> 1
    // myset: 1, 2, 4, 3 (not print 1, 4, 2)
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        // tag some information with the key: number of time it appears, the index, ...
        for (int i = 0; i < nums.size(); i++) {
            // find function return the pointer in the map
            // (1,2), (2,2), (4,1)
            //  ^      ^       ^    ^(end)
            //  begin               end
            // find(1) --> ^ 1
            // find(2) --> ^ 2
            // find(3) --> 3
            if (map.find(nums[i]) == map.end()) { // nums[i] is not a key in the map
                 map[nums[i]] = 1;// the first time    
            }
            else {
                map[nums[i]] += 1;
            }
        } // O(n)
        
        for(auto it = map.begin(); it != map.end(); it++){
            if (it->second == 1) return it->first;
        } // O(n)
        
        // O(n) + O(n) = O(2n) = O(n)
     }
};