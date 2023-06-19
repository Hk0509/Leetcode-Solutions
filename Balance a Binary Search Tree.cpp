class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& store)
    {
        if(root == NULL) return ;

        inOrder(root -> left, store);
        store.push_back(root -> val);
        inOrder(root -> right, store);
    }

    TreeNode* buildBST(int s, int e, vector<int> store)
    {
        if(s>e) return NULL;

        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(store[mid]); 

        root -> left = buildBST(0, mid-1, store);
        root -> right = buildBST(mid+1, e, store);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> store;
        inOrder(root, store);

        return buildBST(0, store.size()-1, store);
    }
};
