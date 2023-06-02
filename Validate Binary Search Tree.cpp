class Solution {
public:
    bool solve(TreeNode* root, long& last)
    {
        if(root == NULL) return 1;
        else if(root -> val <= last) return 0;

        bool left = solve(root -> left, last);
        if(root ->  val <= last) return 0;
        last = root -> val;
        bool right = solve(root -> right, last);
        
        return left & right;
    }

    bool isValidBST(TreeNode* root) {
        long last = -1e10;
        return solve(root, last);
    }
};
