class Solution {
public:
    const int mod = 1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        vector<long long int> dp(2*n);
        dp[1]=1;
        for(int i=2;i<=delay;i++)dp[i]=0;
        for(int i=delay+1;i<=n;i++)
        {
            for(int j = max(i-forget+1,1); j<= i-delay; j++) dp[i]= (dp[i] + dp[j])%mod;
        }
        long long int ans=0;
        for(int i=max(n-forget+1,1);i<=n;i++)ans=  (ans+ dp[i])%mod;
        return ans%mod;
        
    }
};