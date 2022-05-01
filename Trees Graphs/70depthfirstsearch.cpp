// https://visualgo.net/en/dfsbfs
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int visited[N];
void dfs(int vertex)
{
    //O(V+E) is time complexity
    // if(visited[vertex])
    // return;
    cout<<vertex<<endl;
    //take action on vertex after entering vertex
    visited[vertex]=true;
    for(int child:g[vertex])
    {
        cout<<"parent "<<vertex<<" child "<<child<<endl;
        if(visited[child])
        continue;
        //take action on child node before entering child node
        dfs(child);
        //take action on child after entering the child while returning or going back
    }
    //take action on vertex before exiting vertex while returning
    return;
}
int main()
{
int n,m;
cin>>n>>m;
for(int i=1;i<=m;i++)
{
    int v1,v2;
    cin>>v1>>v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}
dfs(g[1][0]);//3 is being considered as root of graph
//dfs(1); //1 is vertex
}

// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6