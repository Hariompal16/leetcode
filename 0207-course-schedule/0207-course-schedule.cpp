class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
         int course = prerequisites[i][0];
          int pre = prerequisites[i][1];

    adj[pre].push_back(course);
}
        queue<int>q;
        vector<int>indegree(numCourses,0);
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
        int count=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[a].size();i++){
                indegree[adj[a][i]]--;
                if( indegree[adj[a][i]]==0){
                    q.push(adj[a][i]);
                }
            }
        }
        if(count==numCourses){
            return true;
        }
        return false;
    }
};