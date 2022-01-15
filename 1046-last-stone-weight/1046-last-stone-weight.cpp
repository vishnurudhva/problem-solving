class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stone_heap;
        for(int stone: stones)
            stone_heap.push(stone);
        while(stone_heap.size() > 1) {
            int num1 = stone_heap.top();
            stone_heap.pop();
            int num2 = stone_heap.top();
            stone_heap.pop();
            int clash = abs(num1 - num2);
            if(clash != 0)
                stone_heap.push(clash);
        }
        return stone_heap.size() == 0 ? 0 : stone_heap.top();
    }
};