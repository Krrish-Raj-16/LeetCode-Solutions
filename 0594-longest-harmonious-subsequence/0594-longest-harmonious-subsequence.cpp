class Solution {
public:

    int findLHS(vector<int>& a) 
    {
        int n=a.size();
        sort(a.begin(), a.end());
        int ans=0;
        int l=0,r=1;
        while(l<=r && r<n)
        {
            if(a[r]-a[l]>1)l++;
            else 
            {
                if(a[r]-a[l]==1) ans=max(ans, r-l+1);
                r++;
            }
        }
        return ans;
    }
};