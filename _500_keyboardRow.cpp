#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <ctype.h>

using namespace std;


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    vector<string> result;
    char array1[10] = {'Q','W','E','R','T','Y','U','I','O','P'};
    char array2[9] = {'A','S','D','F','G','H','J','K','L'};
    char array3[7] = {'Z','X','C','V','B','N','M'};
    unordered_set<char> row1(array1, array1 + 10);
    unordered_set<char> row2(array2, array2 + 9);
    unordered_set<char> row3(array3, array3 + 7);
    // words = ["Hello", "Alaska", "Dad"]
        for (int i = 0; i < words.size(); i++) {  // # iterations = how many words are there (3) , 10^6 words, n words
            // words[0] = "Alaska"
            // cnt1 
            // cnt2 6
            // cnt3 
            int count1 = 0, count2 = 0, count3 = 0;
            for(int j = 0; j < words[i].size(); j++){ // how many character in each words, at most m letters (m can be arbitrary long)
                // search for character toupper(words[i][j]) in row1, row2 or row3
                char c = toupper(words[i][j]);
                if (row1.find(c) != row1.end()){
                    count1++;
                }
                else if (row2.find(c) != row2.end()) {
                    count2++;
                }
                else if (row3.find(c) != row3.end()) {
                    count3++;
                }
                // O(1)
            } // O(m)
            if (count1 == words[i].size() || count2 == words[i].size() || count3 == words[i].size()) {
                result.push_back(words[i]);
            } // tells you if in same row

        } // O(mn)
        return result;
    

        
    }
};



int main() {
    vector<string> words;
    words.push_back("DAD");
    words.push_back("Hello");
    words.push_back("Alaska"); 
    words.push_back("mcnbxzmcbzxcbnz");
    Solution sol;
    vector<string> answer = sol.findWords(words);
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }
    return 0;
}