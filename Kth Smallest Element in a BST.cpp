class Solution {
public:

    void solve(TreeNode* root, vector<int>& store)
    {
        if(root == NULL) return ;

        solve(root -> left, store);
        store.push_back(root -> val);
        solve(root -> right, store);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> store;
        solve(root, store);
        return(store[k-1]);
    }
};
