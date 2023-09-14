class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> route;
    int numOfTickets = 0;
    bool dfs(string fromAirport, vector<string>& temp) {
        temp.push_back(fromAirport);
        if(temp.size() == numOfTickets+1){
            route = temp;
            return true;
        }

        vector<string>& neighbors = adj[fromAirport];
        for(int i = 0; i < neighbors.size(); i++){
            string toAirport = neighbors[i];
            neighbors.erase(neighbors.begin()+i);
            
            if(dfs(toAirport, temp)) return true;
            neighbors.insert(neighbors.begin()+i, toAirport);            
        }
        
        temp.pop_back();
        return 0;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		numOfTickets = tickets.size();
		for(auto it : tickets){
            string u = it[0];
            string v = it[1];
            
			adj[u].push_back(v);
		}

        for(auto &it : adj){
            sort(begin(it.second), end(it.second));
        }
        
        vector<string> temp;
        dfs("JFK", temp);
        return route;
    }
};
