class Solution {
public:
    vector<int> mostCompetitive(vector<int>& a, int k) 
    {
        stack<int> st;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && (n-i+st.size()>k) && a[i]<st.top() )
            {
                st.pop();
            }
            if(st.size()<k)st.push(a[i]);
        }
         vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

        
    }
};