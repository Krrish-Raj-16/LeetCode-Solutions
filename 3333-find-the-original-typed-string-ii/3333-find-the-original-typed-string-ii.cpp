class Solution {
public:
    int m = 1e9 + 7;
    int possibleStringCount(string &s, int k) 
    {
        if (k > s.length())   return 0;
        vector<int> freq;
        int cnt = 1;
        for (int i = 1; i < s.length(); i++) 
        {
            if (s[i] == s[i - 1])  cnt++;
            else 
            {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);
        long long product = 1;
        for (auto f : freq)  product = (product * f) % m;
        if (freq.size() >= k)   return product;
        int n = freq.size();
        vector<vector<int>> t(n + 1, vector<int>(k + 1, 0));
        for (int count = k - 1; count >= 0; count--)  t[n][count] = 1;
        for (int i = n - 1; i >= 0; i--) 
        {
            vector<int> pre(k + 1, 0);
            for (int h = 1; h <= k; h++)   pre[h] = (pre[h - 1] + t[i + 1][h - 1]) % m;
            for (int count = k - 1; count >= 0; count--) 
            {
                int l = count + 1;  
                int r = count + freq[i];
                if (r + 1 > k)  r = k - 1;
                if (l <= r) t[i][count] = (pre[r + 1] - pre[l] + m) % m;
            }
        }
        long long invalidCnt = t[0][0];
        return (product - invalidCnt + m) % m;
    }
};