class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) return NULL;
        if(head -> next == head) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        do
        {
            fast = fast -> next;

            if(fast -> next != NULL)
            fast = fast -> next;
            else return NULL;

            slow = slow -> next;
            cout<<slow -> val<<" ";

            if(fast -> next == NULL) return NULL;
        }
        while(slow != fast);

        fast = head;
        while(fast != slow)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};
