
class Solution {
public:
    struct Compare
    {
        bool operator() (pair<int, int> a, pair<int, int> b)
        {
            float adist = distance(a.first, a.second, 0, 0);
            float bdist = distance(b.first, b.second, 0, 0);
            return adist > bdist;
        }

        float distance(int x1, int y1, int x2, int y2)
        {
            return sqrt(pow(x2 - x1, 2) +
                        pow(y2 - y1, 2) * 1.0);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(int i = 0; i < points.size(); i++)
        {
            pair<int,int> p;
            p.first = points[i][0];
            p.second = points[i][1];
            pq.push(p);
        }
        while(k--) {
            result.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return result;
    }
};

