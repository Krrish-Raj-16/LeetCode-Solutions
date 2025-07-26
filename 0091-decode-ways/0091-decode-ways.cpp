class Solution {
public:
    int numDecodings(string &s) 
    {
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
           int cur = s[i-1]-'0';
           if(cur!=0)  dp[i]=dp[i-1];
           if(i>=2)
           {
              int num = cur+ (s[i-2]-'0')*10;
              if(num>=10 && num<=26) dp[i]+=dp[i-2];
           }
        }
        return dp[n];
    }
};