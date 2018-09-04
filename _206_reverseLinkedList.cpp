#include <iostream>
using namespace std;


  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    // 1->2->3->4
    // 4->3->2->1 
    // return the pointer that points to the head 
    
    // two solutions: one is recursive
    ListNode* reverseList(ListNode* head) {
        return helper(head, NULL);
    }
    ListNode* helper(ListNode* head, ListNode* previous){ // T(n) -> n is the size of the input (we don't know T yet, we want to find T)
        if (head == NULL) return previous; // O(1)
        ListNode* temp = head->next;    // O(1)
        head->next = previous;       // O(1)
        return helper(temp, head);   // T(n-1)
    }
    
    // Find running time of recurive function function has 3 step:
    // call unknown running time T(n) -> n is the size of the input
    // find running of each step (possible have T involved)
    // solve for recursive formula
    
    // T(n) = T(n-1) + O(1)  
    // T(n-1) = T(n-2) + O(1)
    // T(n-2) = T(n-3) + O(1)
    // T(n-3) = T(n-4) + O(1)
    // ...
    // T(2) = T(1) + O(1)
    // T(n) = O(n)   -> solve recursion formula by substitution. (122A)
    // There are three methods to solve for recursion: substitution, master theorem, recursion tree
    
    
    
    // 1->2->3->NULL
    
    //  1 (2->3-NULL)
    // 1<-2 (3->NULL)
    // 1<-2<-3 (head = NULL)

    // one is iterative
    // 1<-2<-3<-4
    // current at 1, temp = 2
    // temp->next = current
    ListNode* reverseList2(ListNode* head) {     
        ListNode *current = head;       // current assigned head
        ListNode *previous = NULL;
        ListNode *temp;
        // 1  -> 2 -> 3 -> NULL
        // head = 1
        // current: 1, 
        // NULL <- 1 <- 2 <- 3
        // current = NULL, 
        // previous = 3

        // 1->2->3->...->n
        while (current != NULL) {
          temp = current->next;        // move forward one node
          current->next = previous; // assign previous
          previous = current;       // flips the pointer
          current = temp;           // moves the current node to the next on
        }
        // O(N) -> N is length of list
        // because cur moves exactly n steps
        
        return previous;
    }
};


int main() {
    return 0;
}