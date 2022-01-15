class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int current = 0, result = 0;
        for(int i = 0; i < plants.size(); i++) {
            if(current < plants[i]) {
                result += i*2;
                current = capacity;
            }
            current -= plants[i];
        }
        return result + plants.size();
    }
};