class Solution {

private:
    int sizeOfList(ListNode* head)
    {
        ListNode* fast = head;

        int count = 0;

        while(fast != NULL)
        {
           fast = fast -> next;
           count++;             
        }
        return count;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
        return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        int len = sizeOfList(head);
        int count = 1;

        if(len - n == 0)
        return head -> next;

        while(count <= len - n)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        if(prev != NULL)
        prev -> next = curr -> next;
        curr -> next = NULL;

        return head;
    }
};
