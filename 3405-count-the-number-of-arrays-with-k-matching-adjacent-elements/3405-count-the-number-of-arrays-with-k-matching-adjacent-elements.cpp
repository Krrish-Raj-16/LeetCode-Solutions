class Solution {
public:
    const int MOD = 1e9 + 7;
    int exp(int x, int n)
    {
        x %= MOD;
        long long int res = 1;
        while (n > 0)
        {
            if (n % 2 == 1)  res = res * x % MOD;
            x = x * x % MOD;
            n /= 2;
        }
        return int(res % MOD);
    }
    int nCr(int n, int r) {

        long long int sum = 1;
        for (int i = 1; i <= r; i++) 
        {
            sum = sum * (n - r + i) / i;
            sum%=MOD;
        }
        return (int)sum;
    }
    int countGoodArrays(int n, int m, int k) {
        long long int ans = m;
        ans = (ans * exp(m - 1, n - k - 1)) % MOD;
        ans %= MOD;
        ans*=nCr(n-1,k);
        return int(ans % MOD);
    }
};