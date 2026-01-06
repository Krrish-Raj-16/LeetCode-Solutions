class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
        int cnt=0;
        int smallest=1000000;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]< 0)cnt++;
                smallest = min(smallest, abs(a[i][j]));
                ans+=abs(a[i][j]);
            }
        }
        if(cnt&1)return ans- 2*smallest;
        return ans;
    }
};