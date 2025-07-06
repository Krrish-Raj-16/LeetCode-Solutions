class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int,int> mp;
        for(auto i: arr)mp[i]++;
        int ans=-1;
        for(auto it: mp)
        {
            if(it.first==it.second)
            {
                if(it.first>ans)ans=it.first;
                
            }
        }
        return ans;
        
    }
};