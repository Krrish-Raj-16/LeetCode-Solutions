class Solution {
public:
    int maxEvents(vector<vector<int>>& a) {
        int d=0, n=a.size(), i=0, ans=0;
        sort(a.begin(), a.end());
        priority_queue<int, vector<int>, greater<>> pq;
        while(i<n || !pq.empty())
        {
            if(pq.empty())
            {
                d=a[i][0];
            }
            while(i<n && a[i][0]==d)
            {
                pq.push(a[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<d)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                d++;
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};