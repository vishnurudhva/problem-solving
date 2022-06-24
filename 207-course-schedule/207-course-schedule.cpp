class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> done(numCourses, false), visited(numCourses, false);
        unordered_map<int, vector<int>> adjList; 
        
        for (vector<int> pre: prerequisites) {
            adjList[pre[0]].push_back(pre[1]);
            
            if (adjList.find(pre[1]) == adjList.end())
                adjList[pre[1]] = {};
        }
        
        for (int i = 0; i < numCourses; i++) {
            if(!done[i] && !canFinishHelper(adjList, i, visited, done))
                return false;
        }
        
        return true;
    }
    
    bool canFinishHelper(unordered_map<int, vector<int>>& adjList, int currentCourse, vector<bool>& visited, vector<bool>& done) {
        if (visited[currentCourse]) return false;
        if (done[currentCourse]) return true;
        visited[currentCourse] = true;
        for (int i = 0; i < adjList[currentCourse].size(); i++) {
            if (!canFinishHelper(adjList, adjList[currentCourse][i], visited, done))
                return false;
        }
        visited[currentCourse] = false;
        done[currentCourse] = true;
        return true;
    }
};