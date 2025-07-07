class Solution {
public:
    int minPathCost(vector<vector<int>>& a, vector<vector<int>>& moveCost) 
    {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>> dp(n, vector<int> (m,10000));

        for(int i=0;i<m;i++)
        {
            dp[0][i]= a[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    dp[i][j]=min(dp[i][j],  dp[i-1][k]+ a[i][j] + moveCost[a[i-1][k]][j]);
                }
            }
        }
       
        return *min_element(dp[n-1].begin(), dp[n-1].end());

        
    }
};