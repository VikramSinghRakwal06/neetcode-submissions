class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto & p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            numCourses--;
            ans.push_back(curr);
            for(auto & n:adj[curr]){
                indegree[n]--;
                if(indegree[n]==0){
                    q.push(n);
                }
            }
        }
        vector<int> n;
        return numCourses==0?ans:n;
    }
};
