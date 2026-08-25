class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>result;
        queue<int>q;
       vector<int>indegree(numCourses,0);
        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];

            adj[v].push_back(u);
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
        result.push_back(node);
        q.pop();
    for(int i=0;i<adj[node].size();i++){
        indegree[adj[node][i]]--;
        if(indegree[adj[node][i]]==0){
            q.push(adj[node][i]);
        }
    }
     }
     if(result.size()!=numCourses){
        return { };
     }
     return result;
    }
};