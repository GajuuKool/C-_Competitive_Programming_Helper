void DFS_bridges(vector<int> adj[], int start, int par, vector<bool> &visited, vector<pair<int,int>> &bridges, int &timer, vector<int> &tin, vector<int> &low)
{
	visited[start] = true;
	tin[start] = low[start] = timer++;
	
	for(int v: adj[start])
	{
		if(v == par)
			continue;
		if(visited[v])
			low[start] = min(low[start], tin[v]);
		else
		{
			DFS_bridges(adj,v,start,visited,bridges,timer,tin,low);
			low[start] = min(low[start],low[v]);
			
			if(low[v] > tin[start])
				bridges.push_back(make_pair(start,v));
		}
	}
} 

vector<pair<int,int>> bridges(vector<int> adj[], int n)
{
	vector<bool> visited(n+1,false);
	vector<int> low(n+1,-1), tin(n+1,-1);
	vector<pair<int,int>> bridges;
	int timer = 0, i;
	
	for(i = 1; i < n+1; i++)
		if(!visited[i])
			DFS_bridges(adj,i,0,visited,bridges,timer,tin,low);
	
	return bridges;
}
