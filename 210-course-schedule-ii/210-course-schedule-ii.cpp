class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course_dependency(numCourses);
        vector<int> degree(numCourses, 0), bfs;
        
        for(vector<int> prerequisite: prerequisites)
        {
            course_dependency[prerequisite[1]].push_back(prerequisite[0]);
            degree[prerequisite[0]]++;
        }
        
        for(int i = 0; i < numCourses; i++)
            if(degree[i] == 0) bfs.push_back(i);
        
        for(int i = 0; i < bfs.size(); i++)
        {
            for(int course: course_dependency[bfs[i]])
                if(--degree[course] == 0)
                    bfs.push_back(course);
        }
        if(bfs.size() != numCourses) return {};
        return bfs;
    }
};