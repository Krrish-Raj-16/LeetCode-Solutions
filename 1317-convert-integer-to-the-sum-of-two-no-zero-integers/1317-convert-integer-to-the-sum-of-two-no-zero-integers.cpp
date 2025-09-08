class Solution {
public:
    bool chk(int n)
    {
        if(n==0)return false;
        while(n>0)
        {
            if(n%10 == 0)return false;
            n/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) 
    {
        for(int i=1;i<=n/2;i++) if((chk(i) && chk(n-i))) return {i,n-i};
        return {-1,-1};
    }
};