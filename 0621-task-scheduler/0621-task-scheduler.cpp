class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> cnt(26, 0);
        for (char t : tasks) cnt[t - 'A']++;
        int ans = 0;
        while (true) 
        {
            sort(cnt.begin(), cnt.end(), greater<int>());
            int i = 0, cycle = 0;
            while (i < 26 && cycle <= n) 
            {
                if (cnt[i] > 0) 
                {
                    cnt[i]--;
                    cycle++;
                }
                i++;
            }
            if (cycle == 0) break;
            ans += (cycle == n + 1) ? cycle : (cnt[0] == 0 ? cycle : n + 1);
        }
        return ans;
    }
};