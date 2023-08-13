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
    ListNode* reverse(ListNode* root)
    {
        ListNode* prev = NULL, *curr = root, *next = NULL;
        while(curr!= NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* add(ListNode* temp1, ListNode* temp2)
    {
        ListNode* temp = new ListNode(-1);
        ListNode* curr = temp;
        int carry = 0;
        while(temp1 != NULL || temp2!= NULL)
        {
            int x=0,y=0;
            if(temp1 != NULL)
            {
                x = temp1->val;
            }
            if(temp2 != NULL)
            {
                y = temp2->val;
            }
            int dig = x + y + carry;
            carry = dig/10;
            dig = dig%10;
            curr->next = new ListNode(dig);
            curr = curr->next;
            if(temp1){
                temp1 = temp1->next;
            }
            if(temp2){
                temp2 = temp2->next;
            }
        }
        if(carry!=0)
        curr->next = new ListNode(carry);
        temp->next = reverse(temp->next);
        return temp->next; 
    }
    ListNode* doubleIt(ListNode* head) {
        if(head == NULL) return NULL;
        head = reverse(head);
        return add(head,head);
        
    }
};
