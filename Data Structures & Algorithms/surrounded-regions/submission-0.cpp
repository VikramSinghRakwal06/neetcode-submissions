class Solution {
public:
    int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
    void dfs(vector<vector<char>>& b, vector<vector<bool>>& vis, int i, int j){
        int r = b.size(), c = b[0].size();
        if(vis[i][j])return;
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int rn = i+dx[k], cn = j+dy[k];
            if(rn<0 || cn<0 || rn>=r || cn>=c || b[rn][cn]=='X')continue;
            else{
                dfs(b,vis,rn,cn);
            }
        }
    }
    void solve(vector<vector<char>>& b) {
        int r = b.size(), c=b[0].size();
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        for(int i = 0;i<r;i++){
            if(b[i][0]=='O'){
                dfs(b,vis,i,0);
            }
            if(b[i][c-1]=='O'){
                dfs(b,vis,i,c-1);
            }
        }
        for(int i = 0;i<c;i++){
            if(b[0][i]=='O'){
                dfs(b,vis,0,i);
            }
            if(b[r-1][i]=='O'){
                dfs(b,vis,r-1,i);
            }
        }
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(b[i][j]=='O'&&!vis[i][j]){
                    b[i][j]='X';
                }
            }
        }
    }
};
