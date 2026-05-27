

class Solution {
public:
    long long count(long long val, vector<int>&a, vector<int>&b)
    {
        long long cnt=0;
        for(int x : a)
        {
            if(x==0 && val>=0)cnt+=b.size();
            else if(x>0)  cnt+=upper_bound(b.begin(), b.end(),floor((long double)val/x))-b.begin();
            else if(x<0) cnt+= b.end()-lower_bound(b.begin(), b.end(), ceil((long double)val/x));
        }
        return cnt;
    }

    long long kthSmallestProduct(vector<int>& a, vector<int>& b,    long long k) {
        int n=a.size();
        int m=b.size();
        long long lo=-1e10, hi=1e10;
        long long mid, ans=0;
        while(lo<=hi)
        {
            mid= lo+ (hi-lo)/2;
            if(count(mid,a,b)>=k)hi=mid-1,ans=mid;
            else lo=mid+1;
        }
        return ans;
    }
};