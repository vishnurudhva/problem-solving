class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegrees(numCourses, 0);
        
        for (vector<int> prerequisite: prerequisites) {
            adjList[prerequisite[1]].push_back(prerequisite[0]);
            inDegrees[prerequisite[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int degree = q.front();
            q.pop();
            numCourses--;
            for (int i = 0; i < adjList[degree].size(); i++) {
                if (--inDegrees[adjList[degree][i]] == 0)
                    q.push(adjList[degree][i]);
            }
        }
        
        return numCourses == 0;
    }
};