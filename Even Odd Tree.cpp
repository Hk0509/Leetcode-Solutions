class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        long prev = -1;
        bool flag = 0;
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL)
            {
                if(flag == 0)
                {
                    prev = 1000001;
                    flag = 1;
                }
                else
                {
                    prev = -1;
                    flag = 0;
                }
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                if((flag == 0 && (front -> val % 2 == 0 || prev >= front -> val)) || (flag == 1 && (front -> val % 2 != 0 || prev <= front -> val))) return 0;
                prev = front -> val;
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
        }
        return 1;
    }
};
