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
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n,0);
        for(auto& e: edges){
            unite(e[0],e[1]);
        }
        int count = 0;

        for(int i = 0;i<n;i++){
            if(parent[i]==i)count++;
        }return count;
    }
};
