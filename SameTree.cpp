class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* r) {
        if(p == NULL && r == NULL) return 1;
        else if((p == NULL && r != NULL) || (p != NULL && r == NULL)) return 0;

        bool left = isSameTree(p -> left, r -> left);
        bool right = isSameTree(p -> right, r -> right);

        bool value = p -> val == r -> val;

        if(left && right && value) return 1;
        else return 0;
    }
};
