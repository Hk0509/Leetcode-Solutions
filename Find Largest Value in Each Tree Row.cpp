/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) 
        return {};

        queue<TreeNode*> q;
        vector<int> ans;
        int maxi = INT_MIN;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                ans.push_back(maxi);
                maxi = INT_MIN;
                if(!q.empty())
                q.push(NULL);
            }
            else{
                maxi = max(front -> val, maxi);
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
        }
        return ans;
    }
};
