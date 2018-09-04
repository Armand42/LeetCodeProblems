#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <sstream>
#include <stack>
#define INF 100000000
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
      /*  stack<string> words;
        istringstream read(s);
        // str = "dog cat cat god"
        while (read >> s) {
            words.push(s);
        }
        string temp = words.top();
        int count = 0;
        for (int i = 0; i < temp.size(); i++) {
            count++;
        }
        return count;
        //cout << temp;
        
        */
        

        int number = 0;
        if (s.length() == 0) {return 0;}
        int end = s.length() - 1;
        while(s[end] == ' ') {
            end--;
        }
        // end is at first character
        
         while(end >=0 && ((s[end] >= 'a' && s[end] <= 'z') || (s[end] >= 'A' && s[end] <= 'Z'))){
            end--;
            number++;
        }
        return number;

        
/*
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                number = i;
                break;
            }

        }
        return number;*/

        // "lkajsd df" -> return 2
        // "lldjf     d   fkdjfdskjfksskf               " -> return 1
        // constant space -> don't have to use any extra space
        // hints:
        // starting from last index (s.length() - 1), skipping all space at the end
        // while (s[end] == ' ') end--;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLastWord("wer      ");

    return 0;
}