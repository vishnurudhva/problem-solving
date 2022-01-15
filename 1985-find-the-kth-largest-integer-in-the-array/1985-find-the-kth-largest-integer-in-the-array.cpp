class Solution {
public:
    struct Compare {
        bool operator()(string const& s1, string const& s2)
        {
            if(s1.length() != s2.length()) return s1.length() < s2.length();
            return s1 < s2;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        int size = nums.size();
        priority_queue<string, vector<string>, Compare> pq;
        for(string& i: nums){
            pq.push(i);
            if(pq.size() > size - k + 1)
                pq.pop();
        }
        return pq.top();
    }
};