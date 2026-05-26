class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            int ind=pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if(vis[ind])continue;
            vis[ind]=true;
            sum+=dis;
            for(int i=0;i<n;i++)
            {
                int curDis = abs(p[i][0]-p[ind][0])+abs(p[i][1]-p[ind][1]);
                if(!vis[i]) pq.push({curDis, i});
            }
        }
        return sum;
        
    }
};