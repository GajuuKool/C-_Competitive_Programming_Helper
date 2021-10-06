void DFS_cut(vector<int> adj[], int start, int par, vector<bool> &visited, vector<int> &points, int &timer, vector<int> &tin, vector<int> &low)
{
	visited[start] = true;
	low[start] = tin[start] = timer++;
	int children = 0;
	
	for(int v: adj[start])
	{
		if(v == par)
			continue;
		if(visited[v])
			low[start] = min(low[start],tin[v]);
		else
		{
			DFS_cut(adj,v,start,visited,points,timer,tin,low);
			low[start] = min(low[start],low[v]);
			
			if(low[v] >= tin[start] && par)
				points.push_back(start);
			
			children++;
		}
	}
	
	if(par == 0 && children >= 2)
		points.push_back(start);
}

vector<int> articulation_points(vector<int> adj[], int n)
{
	vector<bool> visited(n+1,false);
	vector<int> low(n+1,-1), tin(n+1,-1), points;
	int timer = 0, i;
	
	for(i = 1; i < n+1; i++)
		if(!visited[i])
			DFS_cut(adj,i,0,visited,points,timer,tin,low);
	
	return points;
}
