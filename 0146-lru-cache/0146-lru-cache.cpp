class LRUCache {
    int cap;
    list<pair<int,int>>dll;
    unordered_map<int,list<pair<int,int>>::iterator>mp;

public:
    LRUCache(int capacity) :cap(capacity){
    
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end())  return -1;

        dll.splice(dll.begin(),dll,mp[key]); // uss key ko recent mei le aao 
        return mp[key]->second;
    }
    
    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){
            mp[key]->second=value;
            dll.splice(dll.begin(),dll,mp[key]);
            return;
        }

        // agr cap reach 
        if(dll.size()==cap){
            mp.erase(dll.back().first);
            dll.pop_back();
        }


        dll.push_front({key,value});
        mp[key]=dll.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */