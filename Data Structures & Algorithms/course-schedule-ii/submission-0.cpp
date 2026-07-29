class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Create adjacency list and indegree
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        // Push all nodes having indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!q.empty()) {

            int front = q.front();
            q.pop();

            ans.push_back(front);

            for (int nbr : adj[front]) {

                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // If all courses are processed
        if (ans.size() == numCourses)
            return ans;

        // Cycle exists
        return {};
    }
};