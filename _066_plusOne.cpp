#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MainSolution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            int num = digits[i] + carry;
            result.push_back(num%10);
            carry = num / 10;
        }
        // 9 9 9 9
        // 0 0 0 0 1 
        if (carry > 0) 
            result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
   
};

// 1 2 3 4 5
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int sum = 0;
        int counter = 1;
        int expnt = 0;
            /*for (int i = digits.size(); i >=0; i--) {
                sum = (digits[i] * (10^(expnt)))+ sum;
                expnt++;

            }*/

            for (int i = digits.size() - 1; i >= 0; i--) {
                sum += (digits[i] * counter);
                counter = counter * 10;
                //result.push_back(sum);
                //cout << sum << ' ' << endl;
            }
            sum += 1;
            //cout << sum << ' ' << endl;
            while (sum > 0){
                result.push_back(sum % 10);
                sum = sum / 10;
            }
            reverse(result.begin(), result.end());
            return result;
    }
   
};

// 83053
// vector: 8 3 0 9 9
// 83053 + 1 = 83054
// result: 0 0 1 3 8
/// 8 3 1 0 0



void print(vector<int> & a){                // prints out contents of a vector
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}


int main() {

    Solution *solution = new Solution();    // creating a new class object
    int testArray[10] = {9,8,7,6,5,4,3,2,1,0};         // initializing a test array

    vector<int> numbers(testArray, testArray + 10); // placing array data into a new vector of size 5
    vector<int> newResult = solution->plusOne(numbers); // placing numbers vector into function vector parameter
    print(newResult);


    return 0;



}

// FIX THIS
// Do leet
// 2 data structures
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i-1] != nums[i]) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
        
    }
};