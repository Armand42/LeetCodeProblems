#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mymap;      // map contains character and frequency of each character
        
        // s = "abcabcab"
        // t = "aaabbbcc"

        // when counting frequency, you don't need to check membership
        // because default for map is zero
        for (int i = 0; i < s.size(); i++) {
            mymap[s[i]] += 1;
            // if (mymap.find(s[i]) != mymap.end()) { // checks to see if element is in map s
            //     mymap[s[i]] += 1;                   // in map s so increase frequency of that element by 1

            // }
            // else {
            //     mymap[s[i]] += 1;        // not in map increase it by 1 to begin with
                
            // }
        }
        // for the string s
        // mymap: a->0, b ->3, c->2
        // t = "aaabbbcc"
        //  the second for loop make sure the frequency of each character in t is the same as s.
        //  also for changing what is already in the map
        for (int i = 0; i < t.size(); i++) {
            if (mymap.find(t[i]) == mymap.end()) { // checks for different array decremented sizes
                return false;
            }
            else {
                mymap[t[i]] -= 1;
            }
        }
        for (auto it = mymap.begin(); it != mymap.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }
        // check if all frequencies are zero
        // ab
        // map: a->0, b->1
        //     
        return true;
    }
};

// mymap is just generalize of array
// array use keys as index
// a[0] = 1
// a[1] = 2

// map['string'] = 1
// map['slkfjsdlkf'] = 2


int main() {
    Solution sol;
    cout << sol.isAnagram("abc","cab") << endl;

    return 0;
}