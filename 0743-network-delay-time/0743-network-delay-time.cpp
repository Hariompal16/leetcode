class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector< pair<int,int>>>adj(n+1);

       for (auto &e : times) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            
        }
        vector<int>explore(n+1,0);
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});

        while(!q.empty()){
            int node=q.top().second;
            int currweight=q.top().first;
            q.pop();

            if(explore[node]==1) continue;

            explore[node]=1;
            for(int i=0;i<adj[node].size();i++){
                int neighbour=adj[node][i].first;
                int weight=adj[node][i].second;
                if(explore[neighbour]==1) continue;
                if(adj[node][i].second+currweight<dis[neighbour]){
                    dis[neighbour] = currweight + weight;

                    q.push({dis[neighbour], neighbour});
                }
            }
        }
        int maxx=INT_MIN;
        for(int i=1;i<dis.size();i++){
            if(dis[i]==INT_MAX){
                return -1;
            }
            maxx=max(maxx,dis[i]);
        }
        return maxx;
    }
};