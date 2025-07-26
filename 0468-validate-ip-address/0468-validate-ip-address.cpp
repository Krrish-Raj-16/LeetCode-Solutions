class Solution {
public:
    string validIPAddress(string &s) 
    {
        vector<string> ip4;
        string cur = "";
        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '.') 
            {
                ip4.push_back(cur);
                cur = "";
            } 
            else   cur += s[i];
        }
        ip4.push_back(cur);
        if ( s.size()==0 || s[0] == '.' || s[s.size()-1] == '.' ) return "Neither";
        if (ip4.size() == 4) {
            for (int k = 0; k < 4; k++) {
                string x = ip4[k];
                if (x.empty() || x.size() > 3) return "Neither";
                if (x.size() > 1 && x[0] == '0') return "Neither";
                for (char c : x) if (!isdigit(c)) return "Neither";
                long num = stol(x);
                if (num < 0 || num > 255) return "Neither";
            }
            return "IPv4";
        }
        vector<string> ip6;
        cur = "";
        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == ':') 
            {
                ip6.push_back(cur);
                cur = "";
            } 
            else cur += s[i];
        }
        ip6.push_back(cur);
        if (s[0] == ':' || s[s.size()-1] == ':') return "Neither";
        if (ip6.size() == 8) 
        {
            for (int k = 0; k < 8; k++) 
            {
                string x = ip6[k];
                if (x.empty() || x.size() > 4) return "Neither";
                for (char c : x)if (!isxdigit(c)) return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
};
