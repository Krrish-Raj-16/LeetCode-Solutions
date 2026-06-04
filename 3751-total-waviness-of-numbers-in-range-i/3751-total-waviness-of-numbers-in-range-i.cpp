class Solution {
public:
    int count(int n)
    {
        string s= to_string(n);
        if(s.length()<3)return 0;
        int cnt=0;
        for(int i=1;i<s.length()-1;i++)
        {
            if(s[i]>s[i-1] && s[i]>s[i+1])cnt++;
            else if(s[i]<s[i-1] && s[i]<s[i+1])cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1; i<=num2;i++)ans+=count(i);
        return ans;
        
    }
};