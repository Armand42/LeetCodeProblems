#include <iostream>
#include <stack>
using namespace std;
stack <int> digitStack;
class Solution {

public:
    int reverse(int x) {
        // 321 
        bool negative = false;
        if (x == 0) return x;
        if (x < 0){
            negative = true;
            x = -x;
        }
        while (x > 0) {
            //sum = x % 10; // sum = 2
            digitStack.push(x%10); // 1 2 3
            x = x / 10; // x = 3
        }
        
        int counter = 1;
        long sum = 0;
        while (!digitStack.empty()){
            sum += (digitStack.top() * counter); // 1 2 3
            digitStack.pop();
            counter = counter * 10;
        }
        if (sum > INT_MAX || -sum < INT_MIN) return 0;
        cout << INT_MAX << endl;
        cout << sum << endl;
        if (negative) return (int)-sum;
        else return (int)sum;
    }
};




int main() {
    Solution sol;
    cout << sol.reverse(1534236469) << endl;


    return 0;
}