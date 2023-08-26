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
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return 1;

        int left = 1e8, right = 1e8;
        if(root -> left)
        left = 1 + solve(root -> left);
        if(root -> right)
        right = 1 + solve(root -> right);

        return min(left, right);
    }
public:
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};
