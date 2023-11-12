
// It works on DAG only

// vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	   
// 	    queue<int>q;
// 	    vector<int> indegree(V,0);
//      vector<int>ans;
// 
// 	    for(int i=0;i<V;i++)
// 	    {
// 	        for(auto x:adj[i]) indegree[x]++;
// 	    }
// 	    
//      for(int i=0;i<V;i++) if(indegree[i]==0) q.push(i);
// 	    
// 	    while(!q.empty())
// 	    {
// 	        int node = q.front();
// 	        q.pop();
// 
// 	        ans.push_back(node);
// 
// 	        for(auto x:adj[node]) 
//          {
// 	            indegree[x]--;
// 	            if(indegree[x]==0) q.push(x);
// 	        }
// 
// 	    }
// 
// 	    return ans;
// 	}