class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) 
    {
        int ans=0, n=a.size();
        int l=0,r=0,cur=0;
        map<int,int> mp;
        for(r=0;r<n;r++)
        {
            mp[a[r]]++;
            cur+=a[r];
            while(l<=r && r<n && mp[a[r]]>1)
            {
                mp[a[l]]--;
                cur-=a[l];
                if(mp[a[l]]==0)mp.erase(a[l]);
                l++;
            }
            ans=max(ans, cur);
        }
        return ans;
    }
};