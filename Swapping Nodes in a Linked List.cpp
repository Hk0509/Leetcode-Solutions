class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        int len = 0;

        ListNode* temp = head;
        while(temp != NULL)
        {
            temp = temp -> next;
            len++;
        }

        temp = head;
        int count = 1;
        ListNode* nextNode = head;

        while(count<=k || count<=len-k+1)
        {
            count++;  
            if(count <= k) temp = temp -> next;
            if(count <= len-k+1) nextNode = nextNode -> next;  
        }
        
        int x = temp -> val;
        temp -> val = nextNode -> val;
        nextNode -> val = x; 

        return head;
    }
};
