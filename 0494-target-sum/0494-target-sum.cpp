class Solution {
public:
    int solve(vector<int>&a, int tag)
    {
        if(tag<0)return 0;
        int n=a.size();
        vector<vector<int>> dp(n+5, vector<int>(tag+10,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=tag;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=a[i-1])
                {
                    dp[i][j]+=dp[i-1][j-a[i-1]];
                }
            }
        }
        return dp[n][tag];
    }
    
    int findTargetSumWays(vector<int>& a, int target) {
        int total= 0;
        for(auto i:a )total+=i;
        if (abs(target) > total || (total + target) % 2 != 0) return 0;
        return solve(a, (total+target)/2);
    }
};