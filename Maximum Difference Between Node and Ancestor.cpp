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
    int mini(TreeNode* root){
        if(root == NULL) return 1e9;

        int left = min(root -> val, mini(root -> left));
        int right = min(root -> val, mini(root -> right));

        return min({root -> val, left, right});
    }
    int maxi(TreeNode* root){
        if(root == NULL) return -1e9;

        int left = max(root -> val, maxi(root -> left));
        int right = max(root -> val, maxi(root -> right));

        return max({root -> val, left, right});
    }

    void solve(TreeNode* root, int& ans){
        if(root == NULL) return ;
    
        ans = max({ans, abs(root -> val - mini(root)), abs(root -> val - maxi(root))});
        solve(root -> left, ans);
        solve(root -> right, ans);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
