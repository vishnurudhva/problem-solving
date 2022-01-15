class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> map;
        vector<int> result;
        for(int i : nums1)
            map.insert(i);
        for(int i : nums2)
        {
            if(map.find(i) != map.end())
            {
                result.push_back(i);
                map.erase(i);
            }
        }
        return result;
    }
};