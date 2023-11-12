// It works on DAG only

	// void dfs(int node,vector<int>adj[],stack<int>&s,vector<int>&vis)
	// {
	//     vis[node] = 1;
    // 
	//     for(auto x:adj[node])
	//     {
	//         if(!vis[x]) dfs(x,adj,s,vis);
	//     }
	//     s.push(node);
	// }


	// vector<int> topoSort(int V, vector<int> adj[]) 
	// {
	//    
	//     vector<int> vis(V,0);
	//     stack<int>s;
	//     for(int i=0;i<V;i++)
	//     {
	//         if(!vis[i]){
	//             dfs(i,adj,s,vis);
	//         }
	//     }
    // 
	//     vector<int> ans;
	//     while(!s.empty()){ans.push_back(s.top());s.pop();}
	//     return ans;
    // 
	// }