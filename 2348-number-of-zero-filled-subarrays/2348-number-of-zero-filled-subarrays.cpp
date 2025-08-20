class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        int n=a.size();
        vector<int> cnt(n,0);
        int l=0;
        long long ans=0;
        for(int r=0;r<n;r++)
        {
            if(a[r]==0)
            {
                // cout<<r<<" ";
                long long cur=0;
                l=r;
                while(r<n && a[r]==0)r++;
                if(r==n-1 && a[r]==0)cur=r-l+1;
                else cur=r-l;
                ans+=cur*(cur+1)/2;
                r--;
                // cout<<cur<<endl;
            }
        }
        return ans;
    }
};