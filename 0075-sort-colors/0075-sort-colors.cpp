class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
        int lo=0, hi=n-1, mid=0;
        // if(a[hi]==0)swap(a[lo],a[hi]);
        for(mid=0;mid<=hi;mid++)
        {
            if(a[mid]==0)
            {
                swap(a[mid], a[lo]);
                lo++;
            }
            else if(a[mid]==2)
            {
                swap(a[mid], a[hi]);
                hi--;
                mid--;
            }
        }
    }
};