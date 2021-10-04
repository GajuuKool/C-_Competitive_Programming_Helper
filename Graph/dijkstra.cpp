#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<vector<int>> graph(V, vector<int>(V, 0));
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            { // graph[firstVertex][secondVertex] = weight
                graph[i][adj[i][j][0]] = adj[i][j][1];
            }
        }
        vector<int> distance(V, INT_MAX);
        distance[S] = 0;
        vector<bool> visited(V, false);
        // min heap
        // vertex with smallest distance will be always in the front
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //{distance from source, vertex}
        pq.push({0, S});
        while (!pq.empty())
        {
            // u = vertex
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;
            for (int v = 0; v < V; v++)
            {
                // check if edge is there between u and v
                // and if the second vertex is not visited
                if (graph[u][v] != 0 && visited[v] == false)
                {
                    // if previous is distance is greater than the current one
                    if (distance[v] > distance[u] + graph[u][v])
                    {
                        distance[v] = distance[u] + graph[u][v];
                        pq.push({distance[v], v});
                    }
                }
            }
        }
        return distance;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
