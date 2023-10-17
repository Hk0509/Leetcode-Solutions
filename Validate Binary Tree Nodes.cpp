class Solution {
public:
    void dfs(int node, vector<int>* adj, vector<int>& vis, int& cnt){
        vis[node] = 1;
        cnt++;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, cnt);
            }
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int> childToParent;
        vector<int> adj[n];

        //Check whether every child has single parent or not
        for(int i=0; i<n; i++){
            if(childToParent.find(leftChild[i]) != childToParent.end()) return 0;
            else if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
                childToParent[leftChild[i]] = i;
            }
            if(childToParent.find(rightChild[i]) != childToParent.end()) return 0;
            else if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
                childToParent[rightChild[i]] = i;
            }
        }

        //Find root element and check if their is single root or not
        int root = -1;
        for(int i=0; i<n; i++){
            if(root == -1 && childToParent.find(i) == childToParent.end()){
                root = i;
            }
            else if(root != -1 && childToParent.find(i) == childToParent.end()){
                return 0;
            }
        }

        //Check atleast one root exists
        if(root == -1) return 0;
 
        //Check if graph is connected or not
        vector<int> vis(n, 0);
        int cnt = 0;
        dfs(root, adj, vis, cnt);

        return (cnt == n);
    }
};
