class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> temp;
        for(auto n: nums)
        {
            auto it = lower_bound(temp.begin(), temp.end(), n);
            if(it==temp.end()) temp.push_back(n);
            else *it= n;
        }
        return temp.size();
    }
};