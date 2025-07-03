class Solution {
public:
    char kthCharacter(int k) 
    {
        string s="a";
        while(s.length()<k)
        {
            string add="";
            for(int i=0;i<s.length();i++)
            {
                char cur=s[i];
                if(cur=='z')cur='a';
                else cur++;
                add+=cur;
            }
            s+=add;
        }
        return s[k-1];
        
    }
};