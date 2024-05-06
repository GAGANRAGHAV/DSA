#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, Size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        Size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            Size[i] = 1;
        }
    }
    int findUpar(int v)
    { // find parent + path compression
        if (parent[v] == v)
        {
            return v;
        }
        return parent[v] = findUpar(parent[v]);
    }
    void unionbySize(int a, int b)
    {
        a = findUpar(a);
        b = findUpar(b);
        if (a != b)
        { // b ka parent a krna hoga
            if (Size[a] < Size[b])
            { // union by Size
                swap(a, b);
            }
            parent[b] = a; // chote ko bade m jora.
            Size[a] += Size[b];
        }
    }
};


int kruskal(int v, vector<vector<int>> adj[])
{

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            int adjNOde = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjNOde}});
        }
    }

    DisjointSet ds(v);

    sort(edges.begin(), edges.end());

    int mstwt = 0;

    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;


        if(ds.findUpar(u) != ds.findUpar(v))
        {
            ds.unionbySize(u, v);
            mstwt += wt;
        }


    }
    return mstwt;
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


    // int ans = obj.prims(V,adj);
    int mstWt = kruskal(V, adj);


    cout<<mstWt;
}
