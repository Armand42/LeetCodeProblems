#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;
//Input:
// i = [0,0]
// j = 0
// i = [1, 0]
// j = 1
// i = [2,0] 
// j = 2

// three points: [1,0], [0,0], [2,0]
//                 i      j      k
//boomerang: (i,j,k) if distance(i,j) == distance(i,k)
// (x1,y1), (x2,y2) -> d = sqrt((x2-x1)^2 + (y2-y1)^2) -> euclid distance
// [1,0] [0,0] --> 1
// [1,0] [2,0] --> 1


// given n points on the plane (1000), how many boomerangs do you have?

//[[0,0],[1,0],[2,0]]
//   0     1     2
//Output:
//2
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>> & points) {
        int x = 0;
        int y = 0;
        int result = 0;
        long distance = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<long,int> mymap;
            // start from one point: compute frequency distances to find boomerangs to every other points
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                x = points[i].first - points[j].first;
                y = points[i].second - points[j].second;
                distance = (x*x + y*y);
                mymap[distance] += 1;   //increment because we want to keep track of frequency of that distance
            }

            for (auto it = mymap.begin(); it != mymap.end(); it++){
                result += it->second * (it->second -1);
            } 
            // A: {10->3}  -- there are 3 points having distance 10 from A
            // assume {B,C, D} have distance 10 from A
            // A ---------- {B, C, D}, we don't know d(B,C), d(C, D) or d(B, D)
            // boomerang is three points (i,j,k) where d(i,j) = d(i,k)
            // (A, B, C) is a boomerange because d(A,B) = d(A,C) = 10
            // (A, B, D)
            // (A, D, B)
            // (A, C, B)
            // (A, C, D)
            // (A, D, C)
            // boomerange = f(f-1)  
        }
        return result;
    }
};



int main() {
    Solution sol;
    sol.numberOfBoomerangs([[0,0], [1,0], [2,0]]);

    return 0;
}