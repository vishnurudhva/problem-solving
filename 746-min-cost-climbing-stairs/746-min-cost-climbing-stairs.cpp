class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0) return 0;
        if(cost.size() == 1) return cost[0];
        for(int i = cost.size() - 3; i >= 0; i--)
            cost[i] += min(cost[i + 1], cost[i + 2]);
        return min(cost[0], cost[1]);
    }
};