#include <iostream>

using namespace std;


  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public: 
    // f(linkedlist, x) = linkedlist after removing x;
    // f(2->2->3->NULL, 2) = 3->NULL;
    // f(head, x) = (head.next = f(head->next, x)) then removing the head or not depending on head->val = x;
    // 2->2->3->NULL return 3->NULL
    // recursive: 2->3->NULL return 3->NULL
    // recursive: 3->NULL  return 3->NULL
    // recursive: NULL return NULL
 ListNode* removeElements2(ListNode* head, int x) { 
        if (head == NULL) return head;
        head->next = removeElements(head->next, x);
        if (head->val == x) return head->next;
        else return head;
    }
    ListNode* removeElements(ListNode* head, int x) {
        if (head == NULL) return head;  // points to nothing

        // 2->2->NULL
        // 2->NULL current is 2
        // NULL current is NULL
        while (head != NULL && head->val == x) { 
            head = head->next;
        }

        if (head == NULL) return head;
        ListNode *current = head;
        // 2 -> 2 -> 2 -> 3 -> 2  and x = 2
        // 1 -> 3
        

        while (current->next != NULL) { // checks to see if not NULL, and deletes next node by assigning the one after
            if (current->next->val == x) 
                current->next = current->next->next;
            else current = current->next;
        }
        return head;
    }
};

int main() {

    return 0;
}