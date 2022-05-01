#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M=1e9+7;
vector<int> g[N];
int sub_tree[N];
int val[N];
//done
void dfs(int vertex, int par=-1)
{
    // cout << vertex << endl;
    //take action on vertex after entering vertex
    sub_tree[vertex]=sub_tree[vertex]+val[vertex];
    for(int child : g[vertex])
    {
        if (child == par)
            continue;
        //take action on child node before entering child node
        dfs(child, vertex);
        sub_tree[vertex]=sub_tree[vertex]+sub_tree[child];
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
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        int part1=sub_tree[i];
        int part2=sub_tree[1]-sub_tree[i];
        ans=max(ans,(part1*part2)%M);
    }
    

}