class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) 
    {
        int n=a.size();
        vector<vector<int>> dp(n, vector<int>(n,1000));
        if(n==1)return a[0][0];
        for(int i=0;i<n;i++)
        {
            dp[0][i]=a[0][i];
        }
        for(int i=1;i<n;i++)
        {
            dp[i][0]=min(dp[i-1][0], dp[i-1][1])+a[i][0];
            for(int j=1;j<n-1;j++)
            {
                dp[i][j]=min({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]})+a[i][j];
            }
            dp[i][n-1]=min(dp[i-1][n-1],dp[i-1][n-2])+a[i][n-1];
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
        
    }
};