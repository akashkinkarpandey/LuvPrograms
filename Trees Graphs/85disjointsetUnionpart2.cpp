//Find connected Components using DSU
#include <iostream>
using namespace std;
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
        parent[b] = a;//b is small tree ,a of big tree
        size[a]+=size[b];//union by size
    }
}
//Amortized time complexity
//O(alpha(n)) or reverse Ackermann Function
int main()
{
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
    int connected_ct=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)==i)
        connected_ct++;
    }
    cout<<connected_ct<<"\n";
    return 0;
}
// 8 5
// 1 2 
// 2 3
// 2 4
// 3 5
// 6 7


//output is 3

