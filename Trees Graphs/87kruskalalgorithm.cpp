#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//no cycles
//sum of weight of edges is minimum
const int N = 1e5 + 10;
int parent[N];
int size[N];
void make(int v)
{
    parent[v] = v; //makes independent node
    size[v]=1;
}
int find(int v) //returns parent node of that group in whch v is
{
    if (parent[v] == v)
        return v;
    return parent[v]=find(parent[v]);//path compression
}
void Union(int a, int b)
{
    a = find(a);
    //new a is parent node of old a
    b = find(b);
    //new b is parent node of old b
    if (a != b)
    {  //union by size
        if(size[a]<size[b])
            swap(a,b);//big tree will lie on left always for this code
        parent[b] = a;
        size[a]+=size[b];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());
    
    for(int i=1;i<=n;++i)
    make(i);

    int total_cost=0;
    for(auto &edge:edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v))
        continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
}



//input
// 6 9
// 5 4 9
// 1 4 1
// 5 1 4
// 4 3 5
// 4 2 3
// 1 2 2
// 3 2 3
// 3 6 8
// 2 6 7


//output
// 1 4
// 1 2
// 3 2
// 5 1
// 2 6
// 17


