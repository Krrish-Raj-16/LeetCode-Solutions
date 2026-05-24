class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n=a.size();
        if(n<2) return a[0];
        a.insert(a.begin(),1);
        a.push_back(1);
        vector<vector<int>> dp(n+5,vector<int>(n+5,0));
        for(int i=n;i>=1;i--)
            for(int j=i;j<=n;j++)
            {
                for(int k=i;k<=j;k++)
                    dp[i][j]=max(dp[i][j], dp[i][k-1]+dp[k+1][j]+a[i-1]*a[k]*a[j+1]);
            }
        return dp[1][n];
    }
};