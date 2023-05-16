class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* curr = head -> next, *prev = head, *nextNode = curr -> next, *temp = NULL;
        ListNode* newHead = curr;
        while(curr != NULL)
        {
            nextNode = curr -> next;
            if(temp!=NULL) temp -> next = curr;
            curr -> next = prev;
            prev -> next = nextNode;
            temp = prev;
            prev = prev -> next;
            if(prev == NULL) break;
            curr = prev -> next;
        }
        return newHead;
    }
};
