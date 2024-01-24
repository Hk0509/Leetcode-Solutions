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
    map<int, int> mpp;
    int solve(TreeNode* root){
        if(root == NULL) return 0;

        if(!root -> left && !root -> right){
            mpp[root -> val]++;
            int cnt = 0, sum = 0;
            for(auto it: mpp){
               if(it.second & 1) cnt++;
               sum += it.second;
            }
            mpp[root -> val]--;
            if((sum & 1) && (cnt == 1)) return 1;
            else if((sum % 2 == 0) && cnt == 0) return 1;
            return 0;
        }
        mpp[root -> val]++;
        int left = solve(root -> left);
        int right = solve(root -> right);
        mpp[root -> val]--;

        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};
