#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
//make, find , union
void make(int v)
{
    parent[v] = v; //makes independent node which is parent of itself
}
int find(int v) //returns parent node of that group in which v is
{
    if (parent[v] == v)
        return v;
    return find(parent[v]);//we can do path compression here
}
//we want small trees'parent becomes equl to big tree's parent
//merge on basis of rank or size

void Union(int a, int b)
{
    a = find(a);
    //new a is parent node of old a
    b = find(b);
    //new b is parent node of old b
    if (a != b)
        parent[b] = a;
}
int main()
{
    //vertices and edges
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    make(i);
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }

    return 0;
}
