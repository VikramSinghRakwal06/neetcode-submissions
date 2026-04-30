class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        queue<int> q;
        for(auto& p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        for(int i = 0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            numCourses--;
            for(auto &n: adj[curr]){
                indegree[n]--;
                if(indegree[n]==0){
                    q.push(n);
                }
            }
        }
        return numCourses==0;
    }
};
