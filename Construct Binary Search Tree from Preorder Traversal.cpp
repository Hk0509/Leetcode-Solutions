class Solution {
public:
    TreeNode* solve(vector<int>& pre, int maxi, int& i)
    {
        if(i>=pre.size() || pre[i] > maxi) return NULL;
        
        TreeNode* root = new TreeNode(pre[i++]);
        root -> left = solve(pre, root -> val, i);
        root -> right = solve(pre, maxi, i);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int maxi = INT_MAX;
        int i = 0;
        return solve(preorder, maxi, i);
    }
};
