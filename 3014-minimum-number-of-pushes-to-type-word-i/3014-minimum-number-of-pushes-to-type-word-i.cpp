class Solution {
public:
    int minimumPushes(string &s) 
    {
        vector<int> f(26,0);
        int n=s.size(), ans=0;
        for(int i=0;i<n;i++)f[s[i]-'a']++;
        sort(f.begin(), f.end(), greater<int>());
        for(int i=0;i<26;i++)   ans+=  (f[i])*ceil( (double)(i+1)/8.0);
        return ans;
    }
};