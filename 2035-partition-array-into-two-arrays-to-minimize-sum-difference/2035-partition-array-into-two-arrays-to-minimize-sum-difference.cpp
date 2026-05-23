class Solution {
public:
    int minimumDifference(vector<int>& a) {
        int n=a.size()/2;
        int total = accumulate(a.begin(), a.end(), 0);
        vector<vector<int>> leftsum(n+1), rightsum(n+1);
        for(int i=0;i<(1<<n);i++)
        {
            int count=0, lsum=0, rsum=0;
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1)
                {
                    count++;
                    lsum+=a[j];
                    rsum+=a[j+n];
                }
            }
            leftsum[count].push_back(lsum);
            rightsum[count].push_back(rsum);
        }
        for(int i=0;i<=n;i++)
        {
            sort(leftsum[i].begin(), leftsum[i].end());
            sort(rightsum[i].begin(), rightsum[i].end());
        }
        int ans=INT_MAX;

        for(int k=0;k<=n;k++)
        {
            for(int i=0;i<leftsum[k].size();i++)
            {
                int sumLeft = total/2 - leftsum[k][i];
                auto it = lower_bound(rightsum[n-k].begin(), rightsum[n-k].end(), sumLeft);
                if(it!=rightsum[n-k].end())
                {
                    ans= min(ans, abs(total - 2*(*it+leftsum[k][i])));
                }
                if(it!=rightsum[n-k].begin())
                {
                    ans=min(ans, abs(total - 2*( *prev(it) + leftsum[k][i])));
                }
            }
        }
        return ans;
    }
};