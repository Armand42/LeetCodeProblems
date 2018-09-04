#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
/*Example 1:
Given s = "hello", return "holle"

Example 2:
Given s = "leetcode", return "leotcede"
*/

class Solution {
public:
    
    string reverseVowels(string s) {
        int map[256] = {0};
        map['a'] = 1;
        map['i'] = 1;
        map['u'] = 1;
        map['e'] = 1;
        map['u'] = 1;
        map['A'] = 1;
        map['I'] = 1;
        map['U'] = 1;
        map['E'] = 1;
        map['U'] = 1;
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
            while (start < end && map[s[start]] == 0){   // if not a vowel continue to next iteration, increment start
                start++;
            }
            while (start < end && map[s[end]] == 0){   // if not a vowel from end to beginning, decremnt end 
                end--;
            }
            // from the left, increase start until you see vowel
            // from the right, decrease end until you see vowel
            // swap them            
            swap(s[start], s[end]);     // if a vowel, swap the two vowels
            start++; end--;
        }
        // how many iteration:
        // start = 0, end = s.length() - 1
        // at each iteration, start is increasing or end is descreasing --> start and end are getting closer 
       return s; 
    }
};
class Solution {
2
public:
3
    
4
    string reverseVowels2(string s) {
5
        char vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};
6
        unordered_set<char> myset(vowels, vowels + 10);
7
        int start = 0;
8
        int end = s.length() - 1;
9
        while (start < end) {
10
            if (myset.find(s[start]) == myset.end()){   // if not a vowel continue to next iteration, increment start
11
                start++;
12
                continue;
13
            }
14
            if (myset.find(s[end]) == myset.end()){   // if not a vowel from end to beginning, decremnt end 
15
                end--;
16
                continue;
17
            }
18
            // from the left, increase start until you see vowel
19
            // from the right, decrease end until you see vowal
20
            // swap them            
21
            swap(s[start], s[end]);     // if a vowel, swap the two vowels
22
            start++; end--;
23
        }
24
       return s; 
25
    }
26
};


int main() {

    return 0;
}