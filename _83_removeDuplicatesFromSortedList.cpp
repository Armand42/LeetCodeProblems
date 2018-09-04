#include <iostream>
using namespace std;




  
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * head; head->val has type int
                or head->next has type ListNode*
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // input is a pointer to the head of the linkedlist
        // ListNode *  is not the same as ListNode
        ListNode* current = head; // make temp variable so you do not lose information about the head
        
        // if current is NULL, then there is a compile error
        // if the list is empty or the list contain exactly one node.
        // NULL -> current == NULL
        // 2 -> NULL... current -> 2 and current->next is NULL
        // [] empty list: head = NULL
        // [1] : head is the pointer to 1, head->val = 1, head->next = NULL 
        // [1,2]  int head->val = 1, head->next is a pointer to node 2: (head->next)->val = 2
        //  head->val = (*head).val : *head has same type as node
        // ListNode node; 
        // node.val or node.next
        if (current == NULL) {
            return current;
        }
        // 2 -> 2 -> 3 -> 3;
        // ((current->next)->next)->next->val = 3;
        // 2 -> 3 -> 3 -> NULL
        // current at 3: 
        // 2 -> 3 -> NULL
        // current->val == current->next->val : you want to delete the second node.
        while (current->next != NULL) {
            // 1st next, 2nd next, 3rd next
            // if 1st next is not NULL
            if (current->val == (current->next)->val) {
                // 1st next = 2nd next;
                current->next = (current->next)->next;
            }
            else current = current->next;   
        }
        return head;
    }
};




int main() {
    return 0;
}