class Solution {
public:
const int M = 1000000007;
    int exponent(long long int base, long long int exp)
    {
        base%=M;
        long long int ans=1;
        while(exp>0)
        {
            if(exp&1)ans= (ans*base)%M;
            base= (base*base)%M;
            exp>>=1;
        }
        return ans%M;
    }
    vector<int> productQueries(int num, vector<vector<int>>& q) 
    {

        vector<int> pow;
        long long int cur=1;
        while(num>0)
        {
            if(num&1)pow.push_back(log2(cur));
            num=num>>1;
            cur=cur<<1;
        }
        int n=pow.size();
        vector<int> pre(n+1,0);
        pre[0]=0;
        pre[1]=pow[0];
        for(int i=2;i<=n;i++)
        {
            pre[i]=pre[i-1]+pow[i-1];
        }
        vector<int> ans(q.size());
        for(int i=0;i<q.size();i++)
        {
            int l= q[i][0];
            int r= q[i][1];
            ans[i]=exponent(2LL, (long long int) pre[r+1]-pre[l]);
        }
        return ans;
        
    }
};