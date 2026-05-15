class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        //empty constructor
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()){
            return "";
        }
        vector<pair<int, string>> container = store[key];
        int left = 0;
        int right = container.size() - 1;
        string result = "";

        while(left <= right){
            int mid = left + (right-left)/2;

            if(container[mid].first <= timestamp){
                result = container[mid].second;
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        return result;
    }
};
