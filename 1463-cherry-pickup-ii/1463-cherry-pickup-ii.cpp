class Solution {
public:
    int cherryPickup(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        dp[0][0][m-1]=a[0][0]+a[0][m-1];
        for(int i=1;i<n;i++)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int mx=-1;
                    for(int d1=-1;d1<=1;d1++)
                    {
                        for(int d2=-1;d2<=1;d2++)
                        {
                            int ncol1 = j1+d1;
                            int ncol2 = j2+d2;
                            if(ncol1>=0 && ncol1<m && ncol2>=0 && ncol2<m)
                            {
                                mx= max(mx, dp[i-1][ncol1][ncol2]);
                            }
                        }
                    }
                    if(mx!=-1)
                    {
                        int cur = (j1==j2) ? a[i][j1] : a[i][j1] + a[i][j2];
                    dp[i][j1][j2]=cur + mx;
                    }
                    else dp[i][j1][j2]=-1;
                }
            }
        }
        int ans=-1;
        for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    ans=max(ans,dp[n-1][j1][j2]);
                }
            }
            return ans;
    }
};