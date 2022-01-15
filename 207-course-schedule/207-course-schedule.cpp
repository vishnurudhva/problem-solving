class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course_dependency(numCourses);
        vector<int> degree(numCourses, 0), bfs;
        for(vector<int> course_pair: prerequisites)
        {
            course_dependency[course_pair[1]].push_back(course_pair[0]);
            degree[course_pair[0]]++;
        }
        
        for(int i = 0; i < numCourses; i++)
        {
            if(degree[i] == 0)
                bfs.push_back(i);
        }
        
        for(int i = 0; i < bfs.size(); i++)
            for(int course: course_dependency[bfs[i]])
                if(--degree[course] == 0)
                    bfs.push_back(course);
        
        return bfs.size() == numCourses;
    }
    
};