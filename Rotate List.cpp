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

private:
    int countNodes(ListNode* head)
    {
        int n = 0;
        while(head != NULL)
        {
            head = head -> next;
            n++;
        }
        return n;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(head == NULL || head -> next == NULL || k==0)
      return head;

      int n = countNodes(head);
      int count = 1;
      ListNode* curr = head;
      ListNode* prev = NULL;
      ListNode* ans = NULL;

      if(k%n == 0)
      return head;
      
      if(k>n)
      k = k%n;

      while(curr -> next != NULL)
      {
        prev = curr;
        curr = curr -> next;
        if(count == n-k)
        {
          ans = prev -> next;
          prev -> next = NULL;
        }
        count++;
      }  
      curr -> next = head;
      return ans;
    }
};
