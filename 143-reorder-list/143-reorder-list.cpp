class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode* prev = NULL;
        unordered_map<ListNode*, ListNode*> map;
        ListNode* node = head;
        int size = 0;
        while(node) {
            map[node] = prev;
            prev = node;
            node = node->next;
            size++;
        }
        
        ListNode* tail = head;
        while(tail->next)
            tail = tail->next;
        
        int i = 0;
        while(i < size) {
            if(head == NULL || head->next == NULL || head->next->next == NULL) return;
            ListNode* temp = tail;
            tail = map[tail];
            tail->next = NULL;
            
            temp->next = head->next;
            head->next = temp;
            head = temp->next;
            i += 2;
        }
        
    }
};
