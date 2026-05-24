class Solution {
public:
    
    int f(vector<vector<vector<int>>>&dp, vector<int>&a,int i,  int buy, int cap)
    {
        if(cap==0 || i>=a.size())return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        int profit;
        if(buy)  profit= max(-a[i]+ f(dp,a,i+1,0, cap), f(dp,a,i+1, 1, cap));
        else  profit= max(a[i]+ f(dp,a,i+1,1,cap-1), f(dp,a,i+1,0,cap));
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& a){
        int n=a.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        for(int i=n-1;i>=0;i--)
            for(int buy=0;buy<2;buy++)
                for(int cap=1;cap<3;cap++) 
                {
                    if(buy)  dp[i][buy][cap]= max(-a[i]+ dp[i+1][0][cap], dp[i+1][1][cap]);
                    else  dp[i][buy][cap]= max(a[i]+dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
        return dp[0][1][2];
    }
};