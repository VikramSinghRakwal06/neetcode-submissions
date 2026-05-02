class Solution {
public:
    int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
    void dfs(vector<vector<bool>> & vis, vector<vector<int>> & heights,int i, int j){
        int r = heights.size(), c = heights[0].size();
        if(vis[i][j]==true)return;
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int rn = i+dx[k], cn = j+dy[k];
            if(rn>=0 && rn<r && cn>=0 && cn<c && heights[rn][cn]>=heights[i][j]){
                dfs(vis,heights, rn,cn);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> atl(r,vector<bool>(c,false)), pac(r,vector<bool>(c,false));
        for(int i = 0;i<r;i++){
            dfs(atl,heights,i,c-1);
            dfs(pac, heights,i,0 );
        }
        for(int i =0;i<c;i++){
            dfs(atl,heights, r-1,i);
            dfs(pac, heights, 0,i);
        }
        vector<vector<int>> ans;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(pac[i][j]==true&& atl[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
