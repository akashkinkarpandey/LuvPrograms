#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
int n, m;
void dijkstra(int source,vector<pair<int, int>>g[])
{
    vector<bool> vis(n+1, false);
    vector<int> dist(n+1, INF);
    set<pair<int, int>> st;
    // weight,node
    st.insert({0, source});
    dist[source]=0;
    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        cout<<v_dist<<endl;
        st.erase(st.begin());
        if (vis[v])
            continue;
        vis[v] = true;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<" is at distance "<<dist[i]<<endl;
    }
}
int main()
{
    cin >> n >> m;
    vector<pair<int, int>> g[n+1];
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }
    int source;
    cin>>source;
    dijkstra(source,g);
    return 0;
}
//Input
// 6 9
// 1 2 1 
// 1 3 5
// 2 3 2
// 3 5 2
// 2 5 1
// 2 4 2
// 4 5 3
// 4 6 1 
// 5 6 2
// 1

// 0 1 3 3 2 4
// Node 1 is at distance 0
// Node 2 is at distance 1
// Node 3 is at distance 3
// Node 4 is at distance 3
// Node 5 is at distance 2
// Node 6 is at distance 4

