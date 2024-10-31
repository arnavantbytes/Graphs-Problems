bool dfs(vector<bool>&visited,vector<vector<int>>&adj,int u,int parent){

       //this vertex is traversed hence marked true
       visited[u]=true;

       //all the connecting edges of the verted u traversed
       for(auto &v:adj[u]){

           //if its a parent we need to ignore it as think of [1],[0]
           if(v==parent) continue;

           //here if the flow has reached means v is not a prent of u and is visted already then it is a cycle
           if(visited[v]) return true;

           //if not then visit other vertices
           if(dfs(visited,adj,v,u)) return true;
       }

       return false;
   }


    bool isCycle(vector<vector<int>>& adj) {
        //1.creating a bool vector to know which vertex has been traversed
        vector<bool> visited(adj.size(),false);

        //2.checking every vertex to cover cases even when graph is of disconnected type
        for(int u=0;u<adj.size();u++){
            if(!visited[u]) {
                //util function to check cycle
                if(dfs(visited,adj,u,-1)) return true;
            }
        }
        return false;
    }