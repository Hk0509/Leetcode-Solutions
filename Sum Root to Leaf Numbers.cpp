class Solution {
public:
    void solve(TreeNode* root, vector<string>& ans, string& temp)
    {
        if(root == NULL || (root -> left == NULL && root -> right == NULL))
        {
            // temp.pop_back();
            if(root != NULL)
            {
                temp.push_back((root -> val) + '0');
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }

        temp.push_back((root -> val) + '0');
        solve(root -> left, ans, temp);
        solve(root -> right, ans, temp);
        // ans.push_back(temp);
        temp.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        string temp;
        vector<string> ans;
        solve(root, ans, temp);
        int sum = 0;
        for(auto it: ans)
        {
            // cout<<it<<" ";
            sum += stoi(it);
        }
        return sum;
    }
};
