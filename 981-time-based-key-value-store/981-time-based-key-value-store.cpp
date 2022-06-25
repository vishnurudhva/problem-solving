class TimeMap {
public:
    
    unordered_map<string, vector<pair<int, string>>> map;
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (map[key].size() == 0) return "";
        int i = 0, j = map[key].size() - 1, mid;
        while (i <= j) {
            mid = i + (j - i) / 2;
            
            if (map[key][mid].first == timestamp) return map[key][mid].second;
            else if (map[key][mid].first > timestamp) j = mid - 1;
            else i = mid + 1;
        }
        if (i - 1 < 0) return ""; 
        return map[key][i - 1].second;
    }
};








/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */