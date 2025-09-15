class Solution {
public:
    bool isvowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='u' || c=='o')||(c=='A' || c=='E' || c=='I' || c=='U' || c=='O');
    }
    string sortVowels(string &s) {
        int n=s.length();
        vector<char> a;
        for(int i=0;i<n;i++)
        {
            if( isvowel(s[i]))
            {
                a.push_back(s[i]);
                s[i]='*';
            }
        }
        sort(a.begin(), a.end(), greater<int>());
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                s[i]=a.back();
                a.pop_back();
            }
        }
        return s;
        
    }
};