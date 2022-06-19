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
    ListNode* reverseList(ListNode* head, ListNode* nextNode = NULL) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            head->next = nextNode;
            return head;
        }
        ListNode* node = head->next;
        head->next = nextNode;
        nextNode = head;
        return reverseList(node, nextNode);
    }
};