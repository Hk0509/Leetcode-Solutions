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
    void solve(TreeNode* root, map<int, int>& mpp){
        if(root == NULL) return ;

        solve(root -> left, mpp);
        mpp[root->val]++;
        solve(root -> right, mpp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int> mpp;
        solve(root, mpp);
        vector<int> ans(1, 0);
        int maxi = -1e9;
        for(auto it: mpp){
            if(it.second > maxi){
                ans[0] = it.first;
                maxi = it.second;
            }
        }
        for(auto it: mpp){
            if(maxi == it.second && it.first != ans[0]){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
