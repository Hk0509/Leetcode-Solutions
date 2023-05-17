class Solution {
public:

    ListNode* findMid(ListNode* head, ListNode* &prev)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next;

            if(fast == NULL || fast -> next == NULL) prev = slow;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr -> next;

        while(curr != NULL)
        {
            curr -> next = prev;
            prev = curr;
            curr = next;

            if(next != NULL)
            next = next -> next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        if(head == NULL) return 0;
        
        ListNode* prev = NULL;
        ListNode* mid = findMid(head, prev);
        mid = reverseList(mid);
    
        int maxi = INT_MIN;
        while(mid != NULL)
        {
            int sum = head -> val + mid -> val;
            if(maxi<sum) maxi = sum;
            head = head -> next;
            mid = mid -> next;
        }
        return maxi;

    }
};
