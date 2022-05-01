#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
int depth[N];
void dfs(int vertex,int par=-1)
{
    for(int child:graph[vertex])
    {
        if(child==par)
        continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
    }
    return;
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
int maxi=-1;
int node;
for(int i=1;i<=n;i++)
{
    if(depth[i]>maxi)
    {
        maxi=depth[i];
        node=i;
    }
    depth[i]=0;
}
//node stores one end of diameter
dfs(node);
maxi=-1;
for(int i=1;i<=n;i++)
{
    if(depth[i]>maxi)
    {
        maxi=depth[i];
        node=i;
    }
}
//node stores another end of diameter
cout<<"Diameter is "<<maxi<<endl;
}

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

//output 
//8