void DFS_Top(vector<int> adj[], int start, int &label, vector<bool> &visited, vector<int> &order)
{
	visited[start] = true;
	
	for(int v: adj[start])
		if(!visited[v])
			DFS_Top(adj,v,label,visited,order);
	
	order[start] = label--;
}

vector<int> TopSort(vector<int> adj[], int n)
{
	vector<bool> visited(n+1,false);
	int label = n,i;
	vector<int> order(n+1);
	
	for(i = 1; i < n+1; i++)
		if(!visited[i])
			DFS_Top(adj,i,label,visited,order);
	
	vector<int> ordered_nodes(n);
	for(i = 1; i < n+1; i++)
		ordered_nodes[order[i]-1] = i;
	
	return ordered_nodes;
}
