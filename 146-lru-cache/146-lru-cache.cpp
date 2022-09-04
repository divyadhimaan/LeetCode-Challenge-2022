// Head -------MRU--------------------------LRU------------Tail
// Add new node after head
// Remove node before tail

class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            
        }
    };

class LRUCache {
  
public:
    Node* head = new Node(-1,-1);
    Node *tail =  new Node(-1, -1);
    int capacity;
    unordered_map< int, Node*> mp;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        // delete curr;
    }
    
    void addNode(Node* curr)
    {
        curr->next = head->next;
        curr->prev = head;
        
        head->next = curr;
        curr->next->prev = curr;
        
        // return curr;
    }
    
    int get(int key) {
        // key not found
        if(mp.find(key) == mp.end() )
            return -1;
        
        // if key found - return the value - make it most recently used
        Node* curr = mp[key];
        int result = curr->val; 
        
        mp.erase(key);
        deleteNode(curr);
        
        // mp[key] = addNode(new Node(key,result));
        addNode(new Node(key,result));
        mp[key] = head->next;
        
        return result;
    }
    
    void put(int key, int value) {
        
        // node already present in list and map
        if(mp.find(key) != mp.end())
        {
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        
        // want to insert but capacity full - remive LRU node
        if(mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        mp[key] = head->next;
        // mp[key] = addNode(new Node(key,value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */