#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>&vis, vector<int> adj[], stack<int>&s)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, s);
        }
    }
    s.push(node);
}
vector<int> toposort(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);

    vector<int> ans;

    stack<int> s;

    vis[0] = 1;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, s);
        }
    }

    while (!s.empty())
    {
        int a = s.top();
        ans.push_back(a);
        s.pop();
    }

    return ans;
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

    int V = 6;

    vector<int> ans = toposort(6, adj);

    printAns(ans);
}