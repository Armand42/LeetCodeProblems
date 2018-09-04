#include <iostream>
using namespace std;

  
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//  1 -> 2 -> 3 -> 4 ->
//            ^ <-  <-|

// cycle detection: create two pointers, one moving 1 step at a time, the other moving 2 steps at once.
// if there is a cyle, two pointers will meet again
// if there is no cycle, then one will be NULL
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //if (head == NULL) return false;
        //ListNode *current = head;
        ListNode *first = head;    // 2 pointers moving along the list
        ListNode *second = head;
        while (first != NULL && second != NULL && first->next != NULL) {
            first = first->next->next;  // moves up twice
            second = second->next;      // moves up once
            if (first == second) {  // checks to see if pointer is there before
                return true;
                //break
            } 
        }
        //first = head;
        // while (first != second) {
        //     moving both by one step
        // }
        // 1->2->3->4->5->6->7->8->9->10->5
        // O(n/2) -> fast gets to NULL
        // first:  1 3 5 7 9 5 7 1 2 3 4  5
        // second: 1 2 3 4 5 6 7 7 8 9 10 5
        // theorem: they are equal in at most n steps. O(n)
        
        // find the beginning of the cycle: return node 5 (hard) 
        // at the time that they meet, we reset the first to be the head, then we move both of them one step at a time
        // claim: they will meet at the beginning of the cycle
        return false;
    }
};

int main() {
    return 0;
}