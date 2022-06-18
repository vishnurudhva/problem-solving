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
        ListNode* t = head, *h = head;;
        
        while(h != NULL && h->next != NULL) {
            t = t->next;
            h = h->next->next;
            if(t == h) return true;
        }
        
        return false;
    }
};