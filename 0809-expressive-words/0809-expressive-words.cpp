class Solution {
public:
    vector<pair<char,int>> getV(string &s) 
    {
        vector<pair<char,int>> v;
        int cur = 1;
        for(int i = 0; i < s.length()-1; i++) 
        {
            if(s[i] == s[i+1]) cur++;
            else 
            {
                v.push_back({s[i], cur});
                cur = 1;
            } 
        }
        v.push_back({s.back(), cur});
        return v;
    }

    bool check(vector<pair<char,int>> &v, vector<pair<char,int>> &word) 
    {
        if (v.size() != word.size()) return false;
        for (int i = 0; i < v.size(); ++i) 
        {
            if (v[i].first != word[i].first) return false;
            int a = v[i].second, b = word[i].second;
            if (a == b) continue;
            if (a < 3 || b > a) return false;
        }
        return true;
    }

    int expressiveWords(string s, vector<string>& w) {
        int ans = 0;
        vector<pair<char,int>> v = getV(s);
        for (auto& str : w) 
        {
            vector<pair<char,int>> word = getV(str);
            if (check(v, word)) ans++;
        }
        return ans;
    }
};
