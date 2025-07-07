class Solution {
public:
    int longestSubarray(vector<int>& a) 
    {
        int n=a.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        dp[0][0]=a[0];
        int tot=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]==0)
            {
                dp[i][0]=0;
                dp[i][1]=dp[i-1][0];
            }
            else
            {
                tot++;
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1]+1;
            }
        }
        if(tot==n)return n-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            ans=max({ans,dp[i][0], dp[i][1]});
        }
        return ans;
        
    }
};