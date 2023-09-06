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
    int findLen(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head -> next;
        }
        return cnt;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = findLen(head); 
        int parts = len/k;
        int left = len%k;
        vector<int> sizes(k, parts);
        vector<ListNode*> ans(k, NULL);
        if(head == NULL) return ans;
        for(int i=0; i<left; i++){
            sizes[i] += 1;
        }

        ListNode* next = NULL;
        int i = 0, j = 1, cnt = 0;
        ans[0] = head;
        while(head != NULL){
            cnt++;
            if(i<k && cnt == sizes[i]){
                next = head -> next;
                head -> next = NULL;
                head = next;
                if(j<k)
                ans[j] = head;
                i++, j++;
                cnt = 0;
            }
            else
            head = head -> next;
        }
        return ans;
    }
};
