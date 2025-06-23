class Solution {
public:
    int countSquares(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
        int ans=0;
        vector<vector<int>> dp(n+10, vector<int>(m+10,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=a[i][0];
            ans+=dp[i][0];
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=a[0][i];
            ans+=dp[0][i];
        }
        ans-=dp[0][0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(a[i][j]==1)dp[i][j]=min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1;
                else dp[i][j]=0;
                ans+=dp[i][j];
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};