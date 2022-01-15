class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> result(houses.size(), INT_MAX);
        
        for(int i = 0, h = 0; i < houses.size() && h < heaters.size();)
        {
            if(houses[i] <= heaters[h]) { result[i] = heaters[h] - houses[i]; i++; }
            else h++;
        }
        
        for(int i = houses.size() - 1, h = heaters.size() - 1; i >= 0 && h >= 0;)
        {
            if(houses[i] >= heaters[h]) { result[i] = min(result[i], houses[i] - heaters[h]); i--; }
            else h--;
        }
        
        return *max_element(result.begin(), result.end());
        
    }
};