class Solution {
public:
    int partitionArray(vector<int>& a, int k) 
    {
        sort(a.begin(), a.end());
        int n=a.size(), ans=1,curLow=a[0];
        for(int i=0;i<n;i++)
            if(a[i]-k>curLow)
            {
                curLow=a[i];
                ans++;
            }
        return ans;
    }
};