class Solution {
public:
    int numSubseq(vector<int>& a, int target) 
    {
        int n=a.size();
        vector<long long int> pre(n+1,0);
        const long long int mod=1e9+7;
        pre[0]=1;
        for(int i=1;i<=n;i++)
        {
            pre[i]=(pre[i-1]*2)%mod;
        }
        long long int ans=0;
        sort(a.begin(), a.end());
        int l=0, r=n-1;
        while(l<=r)
        {
            if(a[l]+a[r]>target)r--;
            else 
            {
                ans+=(pre[r-l]) ;
                l++;
            }
            ans%=mod;
            
        } 
        return ans;
    }
};