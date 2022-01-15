class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        
        for(int i: nums)
            map[i] = true;
        
        int max_seq = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int curr_num = nums[i];
            int curr_seq_len = 1;
            
            if(!map[curr_num - 1])
            {
                while(map[curr_num + 1])
                {
                    curr_num++;
                    curr_seq_len++;
                }
                
                max_seq = max(curr_seq_len, max_seq);
            }
        }
        
        return max_seq;
    }
};