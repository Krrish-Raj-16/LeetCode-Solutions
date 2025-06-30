class Solution {
public:
    int findLHS(vector<int>& a) 
    {
        int n=a.size();
        map<int,int> mp;
        sort(a.begin(), a.end());
        for(int i=0;i<n;i++)mp[a[i]]++;
        int ans=0;
        for(auto it: mp)
        {
            if(mp.find(it.first+1)!=mp.end())
            {
                ans=max(ans, it.second+ mp[it.first+1]);
            }
        }
        return ans;
    }
};