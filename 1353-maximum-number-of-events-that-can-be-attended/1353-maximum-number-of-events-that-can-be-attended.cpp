class Solution {
public:
	static const bool comp(const vector<int> &a,const  vector<int> &b) {
		if (a[0] != b[0]) 	return a[0] < b[0];
		return a[1] < b[1];
	}
	int maxEvents(vector<vector<int>>& events) 
    {
        int n = events.size();
		int ans = 0;
		int i = 0;
		sort(events.begin(), events.end(), comp);
		multiset<int> s;
		for (int d = 1; d < 100001; ++d) 
        {
			while (!s.empty() && *(s.begin()) < d) 
            {
				s.erase(s.begin());
			}
			while (i < n && events[i][0] == d) 
            {
				s.insert(events[i][1]);
				i++;
			}
			if (s.size() > 0) 
            {
				ans++;
				s.erase(s.begin());
			}
		}
		return ans;
	}
};