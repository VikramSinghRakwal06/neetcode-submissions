class Solution {
public:
    vector<int> parent,rank;
    int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }
    void unite(int u,int v){
        int root_u = find(u), root_v = find(v);
        if(root_u!=root_v){
            if(rank[root_u]>rank[root_v]){
                 parent[root_v]=root_u;
            }else if(rank[root_v]>rank[root_u]){
                 parent[root_u]=root_v;
            }else{
                parent[root_v]=root_u;
                rank[root_u]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
         parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n,0);
        vector<int> ans;
        for(auto &e: edges){
            if(find(e[0])==find(e[1])){ans.push_back(e[0]);ans.push_back(e[1]);}
            else unite(e[0],e[1]);
        }
        return ans;
    }
};
