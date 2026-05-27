class Solution {
public:
    int coinChange(vector<int>& a, int sm) 
    {
        vector<int> dp(sm+1,INT_MAX);
        dp[0]=0;
        for(int amt=1;amt<=sm;amt++)
        {
            for(auto coin: a)
            {
                if(amt>=coin && dp[amt-coin]!=INT_MAX) dp[amt]=min(dp[amt], 1+dp[amt-coin]);
            }
        }  
        return dp[sm]==INT_MAX ? -1 : dp[sm];
    }
};