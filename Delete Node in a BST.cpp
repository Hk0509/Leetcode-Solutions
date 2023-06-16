class Solution {
public:
    int maxVal(TreeNode* root)
    {
        while(root -> right != NULL) root = root -> right;

        return root -> val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root -> val == key)
        {
            //0 child
            if(root -> left == NULL && root -> right == NULL)
            {
                // delete root;
                return NULL;
            }
            //1 child
            if(root -> left == NULL && root -> right != NULL)
            {
                TreeNode* temp = root -> right;
                // delete root;
                return temp;
            }
            if(root -> left != NULL && root -> right == NULL)
            {
                TreeNode* temp = root -> left;
                // delete root;
                return temp;
            }
            //2 child
            if(root -> left != NULL && root -> right != NULL)
            {
                int maxi = maxVal(root -> left);
                root -> val = maxi;
                root -> left = deleteNode(root -> left, maxi);
                return root;
            }
        }
        else if(root -> val > key)
        {
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        else
        {
            root -> right = deleteNode(root -> right, key);
            return root;
        }
        return root;
    }
};
