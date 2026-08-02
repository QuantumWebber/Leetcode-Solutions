class LFUCache {
    int cap, minFreq;

    unordered_map<int, list<pair<int,int>>> fl;            // freq -> uss freq ki list
    unordered_map<int, list<pair<int,int>>::iterator> mp;  // key  -> list me uski jagah
    unordered_map<int, int> cnt;                           // key  -> uska count

    void bump(int key) {
        int f = cnt[key];

        // f wali list se nikaal ke f+1 wali list ke front pe
        fl[f+1].splice(fl[f+1].begin(), fl[f], mp[key]);
        cnt[key] = f + 1;

        if (fl[f].empty() && f == minFreq) minFreq++;
    }

public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        bump(key);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // pehle se hai
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            bump(key);
            return;
        }

        // full hai -> LFU evict
        if ((int)mp.size() == cap) {
            int oldKey = fl[minFreq].back().first;
            fl[minFreq].pop_back();
            mp.erase(oldKey);
            cnt.erase(oldKey);
        }

        fl[1].push_front({key, value});
        mp[key] = fl[1].begin();
        cnt[key] = 1;
        minFreq = 1;
    }
};