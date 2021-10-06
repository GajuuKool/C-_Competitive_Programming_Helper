void DFS_Tree(vector<int> adj[], int start, int par, vector<bool> &visited, bool &isTree)
{
	visited[start] = true;
	for(int v: adj[start])
	{
		if(!visited[v])
			DFS_Tree(adj,v,start,visited,isTree);
		else if(v != par)
		{
			isTree = false;
			break;
		}
	}
}

bool check_tree(vector<int> adj[], int n)
{
	vector<bool> visited(n+1,false);
	bool isTree = true;
	
	DFS_Tree(adj,1,0,visited,isTree);
	
	int i;
	for(i = 1; i < n+1; i++)
		isTree &= visited[i];
	
	return isTree;
}
