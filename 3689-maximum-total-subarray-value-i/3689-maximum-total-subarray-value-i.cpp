class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn=INT_MAX, mx=INT_MIN;
        for(long long i:nums)
        {
            mn=min(mn,i);
            mx=max(mx,i);
        }
        return (mx-mn)*((long long) k);
    }
};