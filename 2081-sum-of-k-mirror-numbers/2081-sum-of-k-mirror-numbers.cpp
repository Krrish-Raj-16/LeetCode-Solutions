class Solution {
public:
    bool check(string &s)
    {
        int n=s.length();
        for(int i=0;i<=n/2;i++)if(s[i]!=s[n-1-i])return false;
        return true;
    }
    string decToK(long long n, long long k)
    {
        string ans="";
        while(n>0)
        {
            ans.push_back( char( n%k +'0'));
            n/=k;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    long long kMirror(int k, int n) 
    {
        vector<long long> pal;
        long long sum=0,id=0,count=0;
        for(int i=1;i<=100000;i++)
        {
            string temp= to_string(i);
            if(check(temp))pal.push_back(i);
            string rev= temp;
            reverse(rev.begin(),rev.end());
            string p1 = temp+rev;
            temp.pop_back();
            string p2= temp+rev;
            pal.push_back(stoll(p1));
            pal.push_back(stoll(p2));
        }
        sort(pal.begin(), pal.end());
        pal.resize(unique(pal.begin(), pal.end()) - pal.begin());
        while(count<n)
        {
            // cout<<pal[id]<<" ";
            string changed= decToK(pal[id],k);
            if(check(changed))
            {
                sum+=pal[id];
                count++;
            }
            id++;
        }
        return sum;
    }
};