class Solution {
public:
    bool dfs(int n, int p, vector<vector<int>>& adj, vector<bool> & vis, int& visCount){
        if(vis[n])return false;
        
        vis[n]= true;
        visCount++;
        for(auto & e: adj[n]){
            if(e==p)continue;
            if(!dfs(e,n,adj,vis,visCount))return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;
     int visCount = 0;
     vector<bool> vis(n,false);
     vector<vector<int>> adj(n);
     for(auto & e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
     }
     if(!dfs(0,-1,adj,vis,visCount))return false;
     return visCount==n;
    }
};
