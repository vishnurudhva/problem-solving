/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *t = head, *h = head;
        
        while (h != NULL && h->next != NULL) {
            t = t->next;
            h = h->next->next;
            if(t == h) break;
        }
        
        if (h == NULL || h->next == NULL) return NULL;
        t = head;
        while(t != h) {
            t = t->next;
            h = h->next;
        }
        
        return t;
    }
};