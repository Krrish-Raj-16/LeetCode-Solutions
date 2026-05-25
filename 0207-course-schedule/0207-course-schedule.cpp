class Solution {
public:
    bool dfs(vector<int>adj[], vector<int>&vis, int node, vector<int>&pathVis)
    {
        vis[node]=true;
        pathVis[node]=true;
        for(auto child: adj[node])
        {
            if(!vis[child])
            {
                if(dfs(adj,vis,child,pathVis))return true;
            }
            else if(pathVis[child])return true;
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> adj[n];
        for(auto i: a) adj[i[1]].push_back(i[0]);
        vector<int> vis(n,0);
        vector<int>pathVis(n,0);
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,i, pathVis)) return false;
            }
        }
        return true;
    }
};