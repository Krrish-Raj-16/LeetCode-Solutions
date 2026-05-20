class TrieNode {
public:
    TrieNode* child[26]={nullptr};
    bool end = false;
};

class Trie {
public:
    TrieNode *root;
    Trie() {
         root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(auto ch : word)
        {
            if(node->child[ch-'a']==nullptr)
            {
                node->child[ch-'a']= new TrieNode();
            }
            node=node->child[ch-'a'];
        }
        node->end=true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(auto ch: word)
        {
            if(node->child[ch-'a']==nullptr)return false;
            node=node->child[ch-'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(auto ch: prefix)
        {
            if(node->child[ch-'a']==nullptr)return false;
            node=node->child[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */