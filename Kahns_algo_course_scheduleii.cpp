class Solution {
public:
    bool kahns_algo(vector<vector<int>>&adj, int n, vector<int> &indegree, vector<int> &ans){
        queue<int> q;
        for(int i = 0; i< n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for( auto a : adj[curr]){
                indegree[a]--;
                if(indegree[a] == 0)
                    q.push(a);
            }
            ans.push_back(curr);
            count++;
        }
        if(count != n)
            return false;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
           indegree[p[0]]++;
        }
        vector<int>ans;
       
        
        if(kahns_algo(adj, numCourses, indegree, ans))
               return ans;
        
        vector<int>empty;
        return empty;    
    }
};
