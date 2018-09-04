#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

    // s = 'abc'
    // t = 'cadb'
    // return: 'd'
    // s = 'abab'
    //  a -> 96
    //  b -> 97
    // sum(s): 96+97+96+97
    // t = 'baabb'
    // sum(t): 97+96+96+97+97
    // return: 'b'

    // duplicates problem: [1,2,3,4,2] --> set (hashtable)
    // set: ['a', 'b','c']
    // loop throught t: and find the one that is not in the set 'd'

    // map: ['a': 2, 'b': 2]
    // 
    // go throught t and check if that character is in my map, 
    char findTheDifference2(string s, string t) {
       
        unordered_map<char,int> mymap;
        for (int i = 0; i < s.size(); i++) {
            if (mymap.find(s[i]) != mymap.end()) {
                mymap[s[i]] += 1;   // increment 1 into frequency if appears multiple times
            }
            else {
                mymap[s[i]] = 1;    // if only appears once set it by 1 still
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (mymap.find(t[i]) == mymap.end() || mymap[t[i]] == 0)  { // if t[i] not in map to be unique or running out of frequencies
                return t[i];
            }
            else {
                mymap[t[i]] -= 1; // decrement frequency to keep track how many times its' already been used
            }
        }
    }
     
    // s='abc'
    // t = 'dacb'

    // size(t) = 1 + size(s)

    char findTheDifference(string s, string t) {
        int n = s.size();
        int sum = t[n]-'a';
        for (int i = 0; i < n; i++) {
            sum += t[i] - 'a';
            sum -= s[i] - 'a';
        }
        return char(sum +'a');

    }


};

int main() {
  
    
    Solution sol;
    sol.findTheDifference("abcd", "abcde");

    return 0;
}