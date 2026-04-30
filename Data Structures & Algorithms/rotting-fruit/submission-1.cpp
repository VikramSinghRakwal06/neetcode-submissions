class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int,int>> q;
           int count = 0;
        for(int i  = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            bool rotted = false;
            while(sz--){
                int ri = q.front().first;
                int ci = q.front().second;
                q.pop();
                for(int i = 0;i<4;i++){
                    int rn = ri+dx[i], cn = ci+dy[i];
                    if(rn>=r || cn>=c || rn<0 || cn<0 || grid[rn][cn]!=1)continue;
                    grid[rn][cn]=2;
                    count--;
                    q.push({rn,cn});
                    rotted = true;
                }
            }if(rotted)time++;
        }
        return count==0?time: -1;
    }
};
