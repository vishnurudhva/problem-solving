class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> visited;
        unordered_set<int> done;
        unordered_map<int, vector<int>> adjList; 
        
        for (vector<int> pre: prerequisites) {
            adjList[pre[0]].push_back(pre[1]);
            
            if (adjList.find(pre[1]) == adjList.end())
                adjList[pre[1]] = {};
        }
        
        for (int i = 0; i < numCourses; i++) {
            if(done.find(i) == done.end() && !canFinishHelper(adjList, i, visited, done))
                return false;
        }
        
        return true;
    }
    
    bool canFinishHelper(unordered_map<int, vector<int>>& adjList, int currentCourse, unordered_set<int>& visited, unordered_set<int>& done) {
        if (visited.find(currentCourse) != visited.end()) return false;
        if (done.find(currentCourse) != done.end()) return true;
        visited.insert(currentCourse);
        for (int i = 0; i < adjList[currentCourse].size(); i++) {
            if (!canFinishHelper(adjList, adjList[currentCourse][i], visited, done))
                return false;
        }
        visited.erase(currentCourse);
        done.insert(currentCourse);
        return true;
    }
};