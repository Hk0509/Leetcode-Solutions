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
    ListNode* findMid(ListNode* head, int size)
    {
        int count = 0;
        while(count < size/2)
        {
            head = head -> next;
            count++;
        }
        return head;
    }

    ListNode* rev(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* currNext = curr -> next;
        while(curr != NULL)
        {
            curr -> next = prev;
            prev = curr;
            curr = currNext;
            if(currNext)
            currNext = currNext -> next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
       ListNode* temp = head;
       int size = 1;

       while(temp -> next != NULL)
       {
           size++;
           temp = temp -> next;
       }

        ListNode* middle = findMid(head, size);

        ListNode* mid = rev(middle);

        temp = head;
        ListNode* tempNext = temp -> next;
        ListNode* midNext = mid -> next;
        while(tempNext != NULL && midNext != NULL)
        {
            temp -> next = mid;
            mid -> next = tempNext;
            temp = tempNext;
            mid = midNext;
            if(midNext)
            midNext = midNext -> next;
            if(tempNext)
            tempNext = temp -> next;
        }
        return ;
    }
};
