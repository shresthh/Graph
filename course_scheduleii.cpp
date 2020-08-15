class Solution {
public:
    bool dfs(int curr, vector<vector<int>> &adj, vector<int> &visited, vector<int> &s){
        visited[curr] = 1;
        for(int i = 0; i< adj[curr].size(); i++){
            if(visited[adj[curr][i]] == 1) return true;
            if(visited[adj[curr][i]] == 0 && dfs(adj[curr][i], adj, visited , s)) return true;
        }
        visited[curr] = 2;
        s.push_back(curr); 
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites)
            adj[p[1]].push_back(p[0]);
        vector<int> visited(numCourses, 0);
        vector<int> s;
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0 && dfs(i, adj, visited, s)) return {};
        }
        reverse(s.begin(), s.end());
        return s;
        
            
        
    }
};
