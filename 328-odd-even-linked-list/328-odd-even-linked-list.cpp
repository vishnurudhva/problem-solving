class Solution {
public:
    ListNode* oddEvenList(ListNode* oddpointer) {
        if(oddpointer == NULL || oddpointer->next == NULL) return oddpointer;
        ListNode* evenpointer = oddpointer->next, *oddhead = oddpointer, *evenhead = evenpointer;
        
        while(oddpointer->next != NULL && oddpointer->next->next != NULL)
        {
            oddpointer->next = oddpointer->next->next;
            oddpointer = oddpointer->next;
            evenpointer->next = oddpointer->next;
            evenpointer = evenpointer->next; 
        }
        oddpointer->next = evenhead;
        return oddhead;
    }
};