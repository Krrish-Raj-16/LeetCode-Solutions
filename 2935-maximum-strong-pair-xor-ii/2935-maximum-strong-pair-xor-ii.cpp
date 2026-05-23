class TrieNode{
    public:
    TrieNode* bits[2]={nullptr};
    int count=0;
};
class Trie{

    TrieNode* root;
    public:
    Trie(){
        root= new TrieNode();
    }
    
    void insert(int n)
    {
        TrieNode* node = root;
        for(int i=20;i>=0;i--)
        {
            int bit = (n>>i)&1;
            if(node->bits[bit]==nullptr)
            {
                node->bits[bit]=new TrieNode();
            }
            node=node->bits[bit];
            node->count++;
        }
    }
    void remove(int n)
    {
        TrieNode* node = root;
        for(int i=20;i>=0;i--)
        {
            int bit = (n>>i)&1;
            node=node->bits[bit];
            node->count--;
        }
    }
    int getXor(int n)
    {
        TrieNode* node = root;
        int xr=0;
        for(int i=20;i>=0;i--)
        {
            int bit=1- ((n>>i)&1);
            if(node->bits[bit]!=nullptr && node->bits[bit]->count>0)
            {
                node=node->bits[bit];
                xr+=(1<<i);
            }
            else node=node->bits[1-bit];
        }
        return xr;
    }

};


class Solution {
public:
    int maximumStrongPairXor(vector<int>& a) {
        int n=a.size();
        sort(a.begin(), a.end());
        Trie tri;
        int id=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            tri.insert(a[i]);
            while(2*a[id]<a[i])
            {
                tri.remove(a[id++]);
            }
            ans=max(ans,tri.getXor(a[i]));
        }
        return ans;
    }
};