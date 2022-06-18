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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return false;
        
        ListNode* t = head->next, *h = t->next;;
        
        while(t != h) {
            if (t->next == NULL) return false;
            t = t->next;
            if (h->next == NULL || h->next->next == NULL) return false;
            h = h->next->next;
        }
        
        return true;
    }
};