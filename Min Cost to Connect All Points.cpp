class Solution {
public:
    int findPar(int val , vector<int>& v){
        if(v[val]==val){
            return val;
        }
        return v[val] = findPar(v[val],v);
    } 
    bool Union(int val1 , int val2 , vector<int>& v , vector<int>& size){
        int v1 = findPar(val1,v);
        int v2 = findPar(val2,v);
        if(v1==v2) return false;
        if( size[v1] > size[v2]){
            v[v2] = v1;
        }
        else{
            v[v2] = v1;
            size[v1]++;
        }
        return 1;
    }  

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                vector<int> temp;
                temp.push_back(dist);
                temp.push_back(i);
                temp.push_back(j);
                edges.push_back(temp);
            }
        }
        sort(edges.begin() , edges.end());
        vector<int> v(n,-1);
        vector<int> size(n,1);
        for(int i=0;i<n;i++) v[i]=i;
        int ans=0;
        for(auto &it: edges){
            bool flag = Union(it[1],it[2],v,size);
            // cout<<flag<<endl;
            if(flag){
                ans+=it[0];
            }
        }
        return ans;

        
    }
};
