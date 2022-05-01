#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int visited[N];
bool dfs(int vertex,int parent)
{
    // cout<<vertex<<endl;
    //take action on vertex after entering vertex
    visited[vertex]=true;
    bool isLoopExists=false;
    for(int child:g[vertex])
    {
        if(visited[child] and child==parent)
        continue;
        if(visited[child])//check for closed cycle
        return true;
        //take action on child node before entering child node
        isLoopExists|=dfs(child,vertex);
        dfs(child,vertex);
        //take action on child after entering the child
    }
    //take action on vertex before exiting vertex
    return isLoopExists;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool isLoopExists=false;
    for(int i=1;i<=n;i++)
    {
        if(visited[i])
        continue;
        if(dfs(i,0))
        {
            isLoopExists=true;
            break;
        }
    }
    cout<<isLoopExists<<endl;
}
// 8 6
// 1 2 
// 1 5
// 2 3
// 2 4
// 3 5
// 3 4
// 6 7
//output is true

// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7
//output is false

