class Solution {
public:
    string largestGoodInteger(string &s) {
        string ans = "";
        int cur =-1;
        for(int i=0;i<s.length()-2;i++)
        {
            string str= s.substr(i,3);
            int num = stoi(str);
            if(num>cur && str[0]==str[1] && str[1]==str[2])
            {
                ans=str;
                cur=num;
            }
        }
        return ans;
        
    }
};