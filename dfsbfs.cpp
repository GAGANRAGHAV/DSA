#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&ans,vector<int>vis)
{
    ans.push_back(node);
    vis[node]=1;

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,ans,vis);
        }
    }

}

vector<int> dfsofgraph(int v, vector<int>adj[])
{
    vector<int>ans;

    vector<int>vis(v,0);
    dfs(0,adj,ans,vis);

    return ans;


}

vector<int> bfs(vector<int>adj[], int n)
{
    vector<int>vis(n,0);

    vis[0]=1;
    
    vector<int>ans;
    queue<int>q;

    q.push(0);

    while (!q.empty())
    {
        int node = q.front();

        ans.push_back(node);

        q.pop();

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }

    return ans;
    


}
void addedge(vector<int>adj[], int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}
void printans(vector<int>&ans)
{
    for(int i=0 ; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    vector <int> adj[5];
    addedge(adj, 0, 1);
    addedge(adj, 1, 2);
    addedge(adj, 1, 3);
    addedge(adj, 0, 4);

    vector<int>ans = dfsofgraph(5,adj);

    printans(ans);



}