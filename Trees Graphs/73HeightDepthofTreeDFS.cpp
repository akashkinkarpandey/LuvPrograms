//depth of root node is zero
//height of leaf node is zero
//for dfs in tree we dont require visited array
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
// int visited[N];
int depth[N];
int height[N];
void dfs(int vertex, int par )
{
    // cout << vertex << endl;
    //take action on vertex after entering vertex
    for (int child : g[vertex])
    {
        if (child == par)
            continue;
        depth[child] = depth[vertex] + 1;
        //take action on child node before entering child node
        dfs(child, vertex);
        height[vertex]=max(height[child]+1,height[vertex]);
        //take action on child after entering the child
    }
    //take action on vertex before exiting vertex
    return;
}
int main()
{
    int n; //vertices input
    cin >> n;
    // int edges = n - 1 ;
    // for trees
    for(int i = 0; i < n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int i=0;i<n-1;i++)
    cout<<depth[i]<<" "<<height[i]<<endl;
    cout<<endl;
}
// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12
// 4 9
// 4 10
// 10 11