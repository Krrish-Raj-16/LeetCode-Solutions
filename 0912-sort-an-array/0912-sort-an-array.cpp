class Solution {
public:
    void merge ( vector<int>&a, int lo, int mid, int hi)
    {
        int i=lo, j=mid+1;
        vector<int>ans;
        while(i<=mid && j<=hi)
        {
            if(a[i]<a[j]) ans.push_back(a[i++]);
            else ans.push_back(a[j++]);
        }
        while(i<=mid)
        {
            ans.push_back(a[i++]);
        }
        while(j<=hi)
        {
            ans.push_back(a[j++]);
        }
        for(int i=lo;i<=hi;i++)a[i]=ans[i-lo];
    }
    void mergeSort(vector<int>&a, int lo, int hi)
    {
        if(hi<=lo)return;
        int mid= (lo+hi)/2;
        mergeSort(a,lo, mid);
        mergeSort(a,mid+1, hi);
        merge(a, lo, mid, hi);
    }

    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<2)return nums;
        mergeSort(nums,0, nums.size()-1);
        return nums;
    }
};