class Solution {
public:
    bool check(string s, string t)
    {
        if(s.length()!=t.length())return false;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i])count++;
            if(count>1)return false;
        }
        return count==1;
    }
    int ladderLength(string st, string ed, vector<string>& list) {
        list.push_back(st);
        int n=list.size();
        vector<int>adj[n+1];
        int li=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(list[i], list[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if(list[i]==ed)li=i;
        }
        if(li==-1)return 0;
        queue<pair<string, int>> q;
        vector<int> dist(n,0);
        dist[n-1]=1;
        q.push({st,n-1});
        while(!q.empty())
        {
            string str= q.front().first;
            int id = q.front().second;
            q.pop();
            for(auto child: adj[id])
            {
                if(dist[child]==0)
                {
                    q.push({list[child], child});
                    dist[child]=dist[id]+1;
                }
            }
        }
        return dist[li];
    }
};