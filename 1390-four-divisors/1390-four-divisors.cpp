class Solution {
public:
    int sumFourDivisors(vector<int>& a) {
        int n=a.size();
        vector<int> d(100004,0);
        vector<long long>m(100004, 0);
        for(int i=1;i<=100000;i++)
        {
            int num =1;
            while(num*i <=100000)
            {
                d[num*i]++;
                if(d[num*i]>4) 
                {
                    num++;
                    continue;
                }
                m[num*i]+=i;
                num++;
            }
        }
        // for(int i=1;i<=20;i++)cout<<i<<" "<<d[i]<<" "<<m[i]<<endl;
        int ans=0;
        for(int i:a)if(d[i]==4)ans+=m[i];
        // for(int i: a) cout<<d[i]<<" "<<m[i]<<endl;
        return ans;
    }
};