class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string cur="";
        for(int i=0;i<s.length();i++)
        {
             cur+=s[i];
             if( (i+1)%k==0)
             {
                ans.push_back(cur);
                cur.clear();
             }
        }
        int rem = k- (s.length()%k);
        if(rem==k)return ans;

        while(rem--)
        {
            cur.push_back(fill);
        }
        ans.push_back(cur);
        return ans;
        
    }
};