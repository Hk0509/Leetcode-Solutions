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
private:
    void dfs(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& ans){
        if(root == NULL) return ;
        if(root -> left == NULL && root -> right == NULL){
            if(targetSum - root -> val == 0){
                temp.push_back(root -> val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return ;
        }

        temp.push_back(root -> val);
        if(root -> left){
            dfs(root -> left, targetSum - root -> val, temp, ans);
        }
        if(root -> right){
            dfs(root -> right, targetSum - root -> val, temp, ans);
        }
        // if(!temp.empty())
        temp.pop_back();
        return ;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> temp;
        dfs(root, targetSum, temp, ans);
        return ans;
    }
};
