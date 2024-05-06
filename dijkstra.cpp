#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, int s, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});

    vector<int> disTO(n, INT_MAX);

    disTO[s] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int a = it[0];
            int b = it[1];

            if (dis + b < disTO[a])
            {
                disTO[a] = dis + b;

                pq.push({dis + b, a});
            }
        }
    }

    return disTO;
}

int main()
{
    int V = 3, S = 2;

    vector<vector<int>> adj[V];

    vector<vector<int>> edges;

    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};

    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> ans = dijkstra(V, S, adj);

  for (int i = 0; i < V; ++i) {
        cout << "Shortest distance from node " << S << " to node " << i << " is " << ans[i] << endl;
    }
    
    }