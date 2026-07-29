class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        // course de rakhe hai complete krne se pehle a b b kop complete kro a se pehle 
        //  total courses bhi hai itne leliye to true vrna flase 


        // sabse adj list 

vector<vector<int>>adj(numCourses);
vector<int>indegree(numCourses,0);

        for(auto& p:prerequisites){
        adj[p[1]].push_back(p[0]);
        indegree[p[0]]++;
        }


        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        // do bfs
        int visited=0;

        while(!q.empty()){
            int front=q.front(); q.pop();
            visited++;

            for(auto nbr: adj[front]){
                indegree[nbr]--;

                if(indegree[nbr]==0){
                    q.push(nbr);
                   
                }
            }
        }
        return visited==numCourses;
    }
};
