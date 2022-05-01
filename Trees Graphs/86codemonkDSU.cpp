// https://cp-algorithms.com/data_structures/disjoint_set_union.html
//https://www.hackerearth.com/challenges/competitive/code-monk-disjoint-set-union/problems/
//city and the campers problems below
#include <iostream>
#include <set>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int size[N];
multiset<int>sizes;
void make(int v)
{
    parent[v] = v; //makes independent node
    size[v]=1;
    sizes.insert(1);
}
int find(int v) //returns parent node of that group in whch v is
{
    if (parent[v] == v)
        return v;
    return parent[v]=find(parent[v]);//path compression
}
void merge(int a,int b)
{
    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));
    sizes.insert(size[a]+size[b]);
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
        merge(a,b);
        size[a]+=size[b];
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    make(i);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
        if(sizes.size()==1)
        cout<<0<<endl;
        else{
            int min=* (sizes.begin());
            int max=*(--sizes.end());
            cout<<max-min<<endl;
        }
    }

}