class Solution {
public:
    int longestSubarray(vector<int>& a) 
    {
        int n=a.size();
        int zero=0;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            cout<<l<<"-"<<r<<endl;
            if(a[r]==0)zero++;
            while(l<=r && zero>1)
            {
                if(a[l]==0)zero--;
                l++;
            }
            ans=max(ans, r-l);
        }
        return ans;
        
    }
};