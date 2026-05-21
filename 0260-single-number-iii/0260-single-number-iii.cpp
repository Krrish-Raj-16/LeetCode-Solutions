class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int xr=0;
        for(auto i: a)xr^=i;
        int sett=0, unset=0;
        for(int i=0;i<32;i++)
        {
            if((1<<i)&xr)
            {
                 for(int num: a)
                 {
                    if((num>>i)&1)sett^=num;
                    else unset^=num;
                 }
                if(sett<unset) return {sett, unset};
                else return {unset, sett};
            }
        }
        return {};
    }
};