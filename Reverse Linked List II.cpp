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
    ListNode* reverse(ListNode* curr, int size, ListNode* &nextNode){
        ListNode* prev = NULL, *next = curr -> next; 
        while(size>=0){
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next)
            next = next -> next;
            size--;
        } 
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head -> next) return head;
        ListNode* prev = NULL, *curr = head, *nextNode = NULL;
        int cnt = 1;
        while(cnt<left){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        int size = right - left;
        ListNode* reversedFront = reverse(curr, size, nextNode);
        if(prev)
        prev -> next = reversedFront;
        else
        head = reversedFront;
        curr -> next = nextNode;

        return head;
    }
};
