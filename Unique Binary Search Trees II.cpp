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
    vector<TreeNode*> solve(int s, int e){
        if(s>e) return {NULL};

        vector<TreeNode*>ans;
        for(int i=s; i<=e; i++){
            vector<TreeNode*> lft = solve(s, i-1);
            vector<TreeNode*> rgt = solve(i+1, e);
            
            for(auto it: lft){
                for(auto jt: rgt){
                    TreeNode* root = new TreeNode(i);
                    root -> left = it;
                    root -> right = jt;
                    ans.push_back(root);
                }
            } 
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};
