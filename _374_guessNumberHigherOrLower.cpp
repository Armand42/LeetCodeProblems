#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
// int guess(int num);
// // guess(i)
// // return -1 if your number is less than num, return 1 if your number is greater than num, or 0 if they equal
// // your number is 10
// // write the function guessNumber(n) --> return 10 
// // use guess(n) -> -1, 1, 0
// // n = 100, guess(100) return 1 
// // guess(5) return -1
// // guess(10) return 0
// class Solution {
// public:
//     int guessNumber(int n) {        // use binary search
//     // 1 2 3 4 5 6 7 8 9 10 (n = 10) correct number is 4
//     //     ^   ^
//     // guess(5) -> return 1
//     // guess(3) -> return -1
//     // guess(4) -> return 0
//     // return 4
//      int start = 1;
//      int end = n;
//      //int lo = 0, hi = (end - start) / sizeof(int) - 1;

//      while(start < end) {
//          int mid = (start + end) / 2;
//          if (guess(mid) == 0) return mid;
//          else if (guess(mid) == -1) { // 1 2 3  ... mid-1  mid   mid + 1 .... n
//             // mid < correct number 
//              start = mid + 1;
//          }
//          else {
//              end = mid - 1;
//          }
//      }
//     }
//     // O(n) -> n = 10^9 --> 10^9 operation
//     // O(log n) -> log(10^9) = 10 operation
// };


int main() {

    int a = INT_MAX;
    int b = INT_MAX - 2;
    cout << a << ' ' << b << endl;

    bitset<32> bitrepr(b);
    cout << bitrepr << endl;
    bitset<32> bitrepr2(-1);
    cout << bitrepr2 << endl;
    // because of overflow
    // int -> 32 bit number , most significant bit is for sign, if it zero, the number is >= 0, if it one, then the number is negative
    // 01111111111111111111111111111111
    // 01111111111111111111111111111101
    // 10000000000000000000000001111100    (2^31-1)  -(2^31)
    cout << a+b << endl;     
    // 4-bit system -> only use 4 bit to represent an integer
    // the first bit is used for sign
    // 0 000 -> 0 001 -> 0 010 ->  0 011 -> 0 100 -> 0 101 -> 0 110 ->  0 111
    // 0        1        2         3        4         5        6        7 (2^3 - 1)
    // 1 000 -> 1 001 -> 1 010 ->  1 011 -> 1 100 -> 1 101 -> 1 110 ->  1 111
    // -8         -7       -6        -5     -4      -3        -2      -1    (two complement)  INT_MIN: -2^3
    //  anser no:  -8 + 1 = 1000 + 0001 = 1001 = -7
    // to find bit of (-6) -->  2^3 - 6 = 2
    //  2 + 7 = 0010 + 0111 =  1001 = -7  -> don't have binary representation for 2+7 = 9 in my system 
    // 1 + 5 = 0001 + 0101 = 0110 = 6 (sum <= 7 and sum >= -8)
    // 0010
    // 0111
    // 1001

    // int -> 32 bit
    // long -> 64 bit
    // -1 representation in int: 11111111111111111111111111111111
    return 0;
}
