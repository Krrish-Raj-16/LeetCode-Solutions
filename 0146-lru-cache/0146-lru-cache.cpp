

class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node *next;
            Node *prev;
            Node(int k,int v): key(k), val(v), next(nullptr), prev(nullptr){}
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int, Node*> mp;

    void deleteNode(Node* cur)
    {
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
    }
    void insertNode(Node* cur)
    {
        cur->next=head->next;
        cur->prev=head;
        head->next=cur;
        cur->next->prev=cur;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head; 
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node *temp = mp[key];
            deleteNode(temp);
            insertNode(temp);
            return temp->val;
        }
        return -1;   
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) //if the map has the key
        {
            Node *temp = mp[key];
            deleteNode(temp);
            insertNode(temp);
            temp->val=value;
        }
        else
        {
            if(mp.size()==cap)
            {
                Node * temp = tail->prev;
                deleteNode(tail->prev);
                mp.erase(temp->key);
            }
            Node* temp = new Node(key, value);
            mp[key]=temp;
            insertNode(temp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */