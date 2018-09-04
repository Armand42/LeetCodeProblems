#include <iostream>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 1 -> 2 -> 3 -> 2 -> 1 -> NULL
        // 1 -> 2 -> 3 -> 2 -> 1 
        // 1
        if (head == NULL) return true;
        ListNode* cur = head;
        ListNode *newHead = new ListNode(cur->val);
        while (cur->next != NULL) {
            ListNode * temp = new ListNode(cur->next->val);
            temp->next = newHead;
            newHead = temp;
        }
        cur = head; ListNode* newCur = newHead;
        while (cur && newCur){
            if (cur->val != newCur->val) return false;
             cur = cur->next;
             newCur = newCur->next;
        }
        return true;
        // ListNode *first = head;
        // ListNode *last = NULL;
        // ListNode *temp;

        // while (first != NULL) {
        //     temp = first->next;
        //     first->next = last;
        //     last = first;
        //     first = temp;
            
        //     if ()

        // }
        
    }
};






int main() {
    return 0;
}