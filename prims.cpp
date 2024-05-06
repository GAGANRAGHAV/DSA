#include<bits/stdc++.h>
using namespace std;

int  prims(vector<vector<int>> adj[], int n)
{
    int mst =0;

    vector<int>vis(n,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    pq.push({0,0});

    while(!pq.empty())
    {
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();

        if(vis[b])
        {
            continue;
        }
        vis[b]= 1;

        mst+=a;

        for(auto it:adj[b])
        {
            if(!vis[it[0]])
            {
                pq.push({it[1],it[0]});

            }

        }

    }

    return mst;



}

int main()
{
    int V = 5;

    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    vector<vector<int>> adj[V];
    vector<int> vis(V, 0);

    for (auto it : edges)
    {
        int node = it[0];
        int dis = it[2];
        int neigh = it[1];

        adj[node].push_back({neigh, dis});
        adj[neigh].push_back({node, dis});
    }

    int a = prims(adj,V);
    cout<<a;
}
