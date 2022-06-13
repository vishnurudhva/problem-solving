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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0), *head = result;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                result->next = l1;
                l1 = l1->next;
            } else {
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }
        
        if (l1 == NULL) result->next = l2;
        else result->next = l1;
        return head->next;
    }
};