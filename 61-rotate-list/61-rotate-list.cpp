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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int count = 0;
        ListNode* temp = head;
        while(++count && temp->next != NULL)
            temp = temp->next;
        
        temp->next = head;
        
        k = k%count;
        if(k > 0) for(int i = 0; i < count - k; i++) temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }
};