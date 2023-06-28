class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        if(head -> next -> val == head -> val && head -> next -> next == NULL) return NULL;
        
        ListNode* temp = head -> next;
        ListNode* prev = head;
        while(temp != NULL && temp -> next != NULL){
            bool flag = 0;
            bool flag1 = 0;

            while(head -> next -> val == head -> val)
            {
                if(head -> next -> next != NULL)
                head = head -> next;
                else return NULL;
                flag1 = 1;
            }
            if(flag1 == 1)
            head = head -> next;

            while(temp -> next != NULL && temp -> next -> val == temp -> val){
                if(temp -> next != NULL)
                temp = temp -> next;
                flag = 1;
            }

            if(flag == 1){
                if(temp -> next != NULL){
                    temp = temp -> next;
                    prev -> next = temp;
                }
                else
                prev -> next = NULL;
            }
            
            else{
            temp = temp -> next;
            prev = prev -> next;
            }
        }
    return head;
    }
};
