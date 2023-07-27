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
    void solve(TreeNode* root, int& count){
        if(root == NULL) return ;

        solve(root -> left, count);
        count++;
        solve(root -> right, count);

        return ;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 0;
        solve(root, count);
        return count;
    }
};
