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
    int ListLength(ListNode* head){
        int length = 0;
        while(head != NULL){
            head = head->next;
            length++;
        }
        return length;
    }
    bool isPalindrome(ListNode* head) {
        int size = ListLength(head);
        if(size <= 1) return true;
        if(size == 2) return head->val == head->next->val;
        ListNode* temp = NULL;     
        ListNode* offset = head;
        ListNode* rev;
        
        for(int i = 0; i < size / 2; i++){
            rev = offset->next;
            offset->next = temp;
            temp = offset;
            offset = rev;
        }
        if(size % 2 == 1)
            offset = offset->next;
        
        while(offset != NULL){
            if(offset->val != temp->val)
                return false;
            offset = offset->next;
            temp = temp->next;
        }
        
        return true;
    }
};