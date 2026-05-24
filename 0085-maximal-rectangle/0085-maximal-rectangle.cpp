class Solution {
public:
    int maxarea(vector<int>&h)
    {
        h.push_back(0);
        stack<int> st;
        int ma=0;
        for(int i=0;i<h.size();i++)
        {
            while(!st.empty() && h[st.top()]>h[i])
            {
                int last = h[st.top()];
                st.pop();
                if(!st.empty())ma=max(ma, last*(i-st.top()-1));
                else ma=max(ma, last*i);
            }
            st.push(i);
        }
        return ma;
    }
    int maximalRectangle(vector<vector<char>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<int> prev(m,0), cur(m,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='1')
                {
                    cur[j]= prev[j]+1;
                }
                else cur[j]=0;
            }
            prev=cur;
            ans=max(ans,maxarea(cur));
        }
        return ans;

        
        
    }
};