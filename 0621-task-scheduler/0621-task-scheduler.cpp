class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(auto c: tasks)mp[c-'A']++;
        priority_queue<int>pq;
        for(auto i:mp)if(i>0)pq.push(i);
        int ans=0;
        while(!pq.empty())
        {
            vector<int>temp;
            int count=0;
            for(int i=0;i<n+1;i++)
            {
                if(pq.empty())
                {
                    break;
                }
                temp.push_back(pq.top()-1);
                pq.pop();
                count++;
            }
            for(auto ii: temp)cout<<ii<<" ";
            cout<<ans<<" "<<endl;
           for(auto num: temp)if(num>0)pq.push(num);
           if(pq.empty())ans+=count;
           else ans+=n+1;
        }
        return ans;
    }
};