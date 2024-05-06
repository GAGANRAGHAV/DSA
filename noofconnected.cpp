#include<bits/stdc++.h>
using namespace std;

int countConnectedComponentsBFS(vector<vector<int>>& adj, int n) {
    vector<bool> vis(n, false);
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
            ++c;
        }
    }
    return c;
}


int main() {
    int n = 9;

    vector<vector<int>> adj(n + 1); 
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[4].push_back(6);
    adj[6].push_back(4);
    adj[7].push_back(8);
    adj[8].push_back(7);
    adj[7].push_back(9);
    adj[9].push_back(7);
    adj[8].push_back(9);
    adj[9].push_back(8);

    int connectedComponentsBFS = countConnectedComponentsBFS(adj, n);

    if (connectedComponentsBFS == 1) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
        cout << "Number of connected components: " << connectedComponentsBFS << endl;
    }

    return 0;
}
