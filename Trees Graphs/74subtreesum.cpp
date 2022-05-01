//for dfs in tree we dont require visited array
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
// int visited[N];
//given Q queries
//In each query given V,
//Print subtree sum of V and number of even numbers
//in subtree of V
int sub_tree[N];
int evencnt[N];
int depth[N];
int height[N];
void dfs(int vertex, int par=0)
{
    // cout << vertex << endl;
    //take action on vertex after entering vertex
    sub_tree[vertex]=sub_tree[vertex]+vertex;
    if(vertex%2==0)
    evencnt[vertex]++;
    for(int child : g[vertex])
    {
        if (child == par)
            continue;
        //take action on child node before entering child node
        dfs(child, vertex);
        sub_tree[vertex]=sub_tree[vertex]+sub_tree[child];
        evencnt[vertex]=evencnt[vertex]+evencnt[child];
        //take action on child after entering the child
    }
    //take action on vertex before exiting vertex
    return;
}
int main()
{
    int n; //vertices input
    cin >> n;
    // int edges = n - 1;
    for(int i = 0; i < n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    for(int i=1;i<=n;i++)
    cout<<sub_tree[i]<<" "<<evencnt[i]<<endl;
    
    // int q;
    // cin>>q;
    // while(q--)
    // {
    //     int v;
    //     cin>>v;
    //     cout<<sub_tree[v]<<" "<<evencnt[v]<<endl;
    // }
}
//input

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

//output

// 91 6
// 40 4
// 37 2
// 34 2
// 38 3
// 6 1
// 7 0
// 20 2
// 9 0
// 21 1
// 11 0
// 12 1
// 13 0