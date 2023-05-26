class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL)
        return head;

        ListNode* curr = head -> next;
        ListNode* prev = head;
        ListNode* next = curr -> next;

        while(curr != NULL)
        {
            if(prev -> val == curr -> val)
            {
                prev -> next = next;
                curr -> next = NULL;
                delete(curr);
                curr = next;
                if(next != NULL)
                next = curr -> next;
            }
            else
            {
                prev = curr;
                curr = next;
                if(next != NULL)
                next = curr -> next;
            }
        }
        return head;
        
    }
};
