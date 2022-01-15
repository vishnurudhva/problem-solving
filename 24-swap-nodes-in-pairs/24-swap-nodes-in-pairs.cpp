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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = head->next, *temp;
        while(head->next != NULL && head->next->next != NULL)
        {
            temp = head->next->next;
            head->next->next = head;
            head->next = temp->next;
            head = temp;
        }
        if(head->next != NULL)
        {
            head->next->next = head;
            head->next = NULL;
        }else{
            temp = newHead;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = head;
        }
        return newHead;
    }
};