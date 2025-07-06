class Solution {
public:
    int twoEggDrop(int n) 
    {
        vector<vector<int>> dp(n+2, vector<int>(3, 0));
        int moves = 0;
        while (dp[moves][2] < n) 
        {
            moves++;
            dp[moves][1] = moves;
            dp[moves][2] = 1 + dp[moves-1][1] + dp[moves-1][2];
         }
        return moves;   
    }
};