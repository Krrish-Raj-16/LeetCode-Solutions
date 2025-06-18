class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& a, int k) 
    {
        sort(a.begin(), a.end());
        int n=a.size();
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<n;i+=3)
        {
            ans.push_back({{a[i], a[i+1], a[i+2]}});
        }
        for(int i=0;i<n/3;i++)
        {
            if(ans[i][2]- ans[i][0] >k)
            {
                ans.clear();
                break;
            }
        }
        return ans;
    }
};