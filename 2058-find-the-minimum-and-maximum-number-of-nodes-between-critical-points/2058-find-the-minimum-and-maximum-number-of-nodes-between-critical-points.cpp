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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL) return {-1, -1};
        int k = 0, count = 1;
        vector<int> arr;
        ListNode* node = head->next;
        int prev = head->val;
        while(node->next != NULL) {
            if((prev < node->val && node->val > node->next->val) || (prev > node->val && node->val < node->next->val))
                arr.push_back(count);
            prev = node->val;
            count++;
            node = node->next;
        }
        if(arr.size() <= 1) return {-1, -1};
        
        int minDist = arr[arr.size() - 1] - arr[0];
        for(int i = 0; i < arr.size() - 1; i++)
            minDist = min(arr[i + 1] - arr[i], minDist);
        
        return {minDist, arr[arr.size() - 1] - arr[0]};
    }
};