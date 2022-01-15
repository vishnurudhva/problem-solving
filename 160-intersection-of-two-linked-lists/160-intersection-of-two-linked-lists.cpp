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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        int A = 0, B = 0;
        while(tempA != NULL) {
            A++;
            tempA = tempA->next;
        }
        ListNode* tempB = headB;
        while(tempB != NULL) {
            B++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        if(A > B)
            for(int i = 0; i < A - B; i++)
                tempA = tempA->next;
        else
            for(int i = 0; i < B - A; i++)
                tempB = tempB->next;
        while(tempA != NULL && tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};