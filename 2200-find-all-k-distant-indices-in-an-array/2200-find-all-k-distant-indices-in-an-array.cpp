class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int key, int k) 
    {
        int n = a.size();
        vector<int> ans;
        int left =0, right=0;
        for (int j = 0; j < n; ++j) 
        {
            if (a[j] == key) 
            {
                left = max(right, j - k);
                right = min(n, j + k+1);
                for (int i = left; i < right; ++i) ans.push_back(i);
            }
        }
        return ans;
    }
};