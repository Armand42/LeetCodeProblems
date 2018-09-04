#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1.push_back(nums2.at(i));
            
        }
        sort(nums1.begin(), nums1.end()); // O(nlogn)
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(n+m);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin()+n, result.begin());
        swap(result, nums1);
    }

    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0;
        int j = 0;
        while (i < m && j < n){
            if (nums1[i] < nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }
            else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {                     // if one array is bigger than the other
            result.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            result.push_back(nums2[j]);
            j++;
        }
        swap(nums1, result);
    }

    // 1 3 3 5 9
    // 2 2
    // 1  2  2 
         
    // void sort2(vector<int>& a) {     
    //     int temp = 0;
    //     for (int i = 0; i < a.size()-1; i++) {
    //         for (int j = 0; j < a.size() - i - 1; j++) {
    //             if (a[j] > a[j+1]) { 
    //                 temp = a[j];
    //                 a[j] = a[j+1];
    //                 a[j+1] = temp;

    //             }
    //         }
    //     }
    // }

    // O(n^2) algorithm


    
};


void print(vector<int>  & a){
    for(int i = 0; i < a.size(); i++){
        cout << a.at(i) << ' ';
    }
    cout << endl;
}


int main() {
    Solution sol;

    int arr1[5] = {1,2,3,4,5};
    int arr2[4] = {3,6,7,11};

    vector<int> test1(arr1, arr1 + 5);
    vector<int> test2(arr2, arr2 + 4);

    sol.merge(test1,5,test2,4);
    
    print(test1);
    //print(test2);

    return 0;
}



