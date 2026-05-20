class Node{
    public:
        Node *bits[2]={nullptr};
};

class Trie{
    Node *root= new Node();
    public:
        void insert(int num)
        {
            Node *node = root;
            for(int i=31;i>=0;i--){
                int bit = 1&(num>>i);
                if(node->bits[bit]==nullptr) node->bits[bit]=new Node();
                node=node->bits[bit];
            }
        }
        int getXor(int num)
        {
            Node *node=root;
            int xorr=0;
            for(int i=31;i>=0;i--)
            {
                int bit = 1-(1&(num>>i));
                if(node->bits[bit]!=nullptr)
                {
                    xorr+=1<<i;
                    node=node->bits[bit];
                }
                else node=node->bits[1-bit];
            }
            return xorr;
        }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(), nums.end());
        vector<vector<int>> offlineQueries;
        for(int i=0;i<queries.size();i++) {
            offlineQueries.push_back({queries[i][1],queries[i][0],i});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        vector<int> ans(queries.size());
        int id=0;
        for(int i=0;i<queries.size();i++)
        {
            while(id<nums.size() && nums[id]<=offlineQueries[i][0])
            {
                trie.insert(nums[id++]);
            }
            if(id==0) ans[offlineQueries[i][2]]=-1;
            else ans[offlineQueries[i][2]]=trie.getXor(offlineQueries[i][1]);
        }
        return ans;
    }
};