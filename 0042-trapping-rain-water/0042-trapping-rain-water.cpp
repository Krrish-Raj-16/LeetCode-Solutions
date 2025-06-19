class Solution {
public:
    int trap(vector<int>& a) 
    {
        int n=a.size(),ans=0;
        vector<int> ngr(n),ngl(n);
        ngr[n-1]=a[n-1];
        ngl[0]=a[0];
        for(int i=n-2;i>=0;i--)   ngr[i]=max(ngr[i+1],a[i]); 
        for(int i=1;i<n;i++)   ngl[i]=max(ngl[i-1],a[i]);
        for(int i=0;i<n;i++)
        {
            if(ngl[i]==-1 || ngr[i]==-1 )continue;
            else ans+=min(ngl[i],ngr[i])-a[i];
        }
        return ans;   
    }
};