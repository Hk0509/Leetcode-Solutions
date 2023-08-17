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
    bool isSim(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return 1;
        if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL)) return 0;
        if(root1 -> val != root2 -> val) return 0;
        // if(root1 -> val != root2 -> val) return 0;

        bool check1 = isSim(root1 -> left, root2 -> right);
        bool check2 = isSim(root1 -> right, root2 -> left);

        return (check1 && check2);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSim(root -> left, root -> right);
    }
};
