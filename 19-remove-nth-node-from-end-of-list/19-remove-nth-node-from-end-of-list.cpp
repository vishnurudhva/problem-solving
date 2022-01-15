/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count = 0;
        ListNode* node = head;
        
        while(node && ++count)
            node = node->next;
        
        if(n == count) return head->next;
        
        node = head;
        count -= n;
        
        while(node && --count)
            node = node->next;
        
        node->next = node->next->next;
        return head;
    }
};