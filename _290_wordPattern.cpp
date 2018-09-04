#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        string s;
        istringstream read(str);
        // str = "dog cat cat god"
        while (read >> s) {
            words.push_back(s);
        }
        // pattern = "abbc"
       //  words = ["dog", "cat", "cat", "god"]
       // b --> cat
       // b --> cat

       // pattern = "abbc"
       // words = ["cat", "cat", "dog"]  -> return false

       if (pattern.size() != words.size()) return false;

       // map --> binary search tree
       // find : O(log n) time
       // give the order of key (descreasing or increasing)
       unordered_map<char, string> map1;
       // hashtable(<key,value>): find: O(1)

       unordered_set<string> myset;
       // hashtable (key)
       // find : O(1)
        for(int i = 0; i < pattern.size(); i++) {
            if ( map1.find(pattern[i]) == map1.end()){ // checking to see if not in map/if not in map it puts it in
                // is the words not the same as any others words in the map
                //for(map<char, string>::iterator it = map1.begin(); it != map1.end(); it++){
                  //  if (it->second == words[i]) return false; // to make sure things that are already mapped aren't changed
                //} // O(n)
                if (myset.find(words[i]) != myset.end()) return false; // checks to see if already been assigned to some character
                // a -> cat
                // b -> dog
                // c cat --> cat
                map1[pattern[i]] = words[i];
                myset.insert(words[i]); // keeping track of the words that have already been assigned to each character
            }
            else{
                if (map1[pattern[i]] != words[i]) return false;
                // b --> cat
                // b --> cat
                // checks to see if they are the same/same character should map to the same word
            }
            
        }// O(n)
        return true;
    }
};

// pattern = "cda" 
// words = "apple apple orange" return false
// words = "apple banana orange" return true

// pattern = "abacabaccbabcbacbabcac"
// words = "he she he she" return false
// words = "he she he her he she he her her she he she .." return true

// mapping:
// a -> he
// b -> she
// a -> he
// c -> her
// unordered_map: 



int main() {
    Solution sol;

    cout << sol.wordPattern("abc", "cat dog cat") << endl;






    return 0;
}