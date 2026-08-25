class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        int count=0;
        queue<int>q;
       vector<int>indegree(numCourses,0);
        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
        }
     for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
     }

     for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
     }

     while(!q.empty()){
        int node=q.front();
        count++;
        q.pop();
    for(int i=0;i<adj[node].size();i++){
        indegree[adj[node][i]]--;
        if(indegree[adj[node][i]]==0){
            q.push(adj[node][i]);
        }
    }
     }
     return count==numCourses;
        
    }
};