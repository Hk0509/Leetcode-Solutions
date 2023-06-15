class Solution {
public:
    // pair<int, int> bfs(TreeNode* root)
    // {
    //     pair<int, int> ans = make_pair(INT_MIN,0);
    //     queue<TreeNode*> q;
    //     pair<int, int> sum = make_pair(0,0);
    //     q.push(root);
    //     q.push(NULL);
    //     while(!q.empty())
    //     {
    //         TreeNode* front = q.front();
    //         q.pop();
    //         if(front == NULL)
    //         {
    //             sum.second++;
    //             if(sum.first>ans.first) ans = sum;
    //             sum.first = 0;
    //             if(!q.empty()) q.push(NULL);
    //         }
    //         else
    //         {
    //             sum.first += front -> val;
    //             if(front -> left) q.push(front -> left);
    //             if(front -> right) q.push(front -> right);
    //         }
    //     }
    // return ans;
    // }

    void dfs(TreeNode* root, vector<int>& sum, int &level)
    {
        if(root == NULL) return ;

        if(level<sum.size())
        sum[level] += root -> val;
        else
        sum.push_back(root -> val);

        dfs(root -> left, sum, level+=1);
        level = level - 1;

        dfs(root -> right, sum, level+=1);
        level = level - 1;

        return ;
    }

    int maxLevelSum(TreeNode* root) {
        // return bfs(root).second;

        int level = 0;
        vector<int> sum;
        dfs(root, sum, level);
        pair<int, int> ans = make_pair(0, INT_MIN);
        for(int i=0; i<sum.size(); i++)
        {
            if(ans.second<sum[i])
            {
             ans.first = i;
             ans.second = sum[i];
            }
        }
        return ans.first+1;
    }
};
