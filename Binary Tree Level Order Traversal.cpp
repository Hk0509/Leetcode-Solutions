class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL)
            {
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                temp.push_back(front -> val);
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
        }
        return ans;
    }
};
