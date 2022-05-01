#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
int parent[N];
void dfs(int vertex,int par=-1)
{
    parent[vertex]=par;
    for(int child:graph[vertex])
    {
        if(child==par)
        continue;
        dfs(child,vertex);
    }
}
vector<int> path(int vertex)
{
    vector<int>ans;
    while(vertex!=-1)
    {
        ans.push_back(vertex);
        vertex=parent[vertex];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
int n;
cin>>n;
for(int i=0;i<n-1;i++)
{
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
}
dfs(1);
int x,y;
cin>>x>>y;
vector<int>path1=path(x);
vector<int>path2=path(y);
int mini=min(path1.size(),path2.size());
int lca=-1;
for(int i=0;i<mini;i++)
{
    if(path1[i]==path2[i])
    lca=path1[i];
}
cout<<lca<<"\n";
return 0;
}
//above is O(N)
//binary uplifting is O(log N)

// 13 
// 1 2
// 1 3
// 1 13
// 2 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10
// 10 11
//6 7

//output
//5
