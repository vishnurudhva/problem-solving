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
        if(head == NULL || head->next == NULL) return false;
        ListNode* t = head->next;
        ListNode* h = t->next;
        
        while(t != h)
        {
            if(t == NULL || h == NULL || h->next == NULL) return false;
            t = t->next;
            h = h->next->next;
        }
        
        return true;
    }
};