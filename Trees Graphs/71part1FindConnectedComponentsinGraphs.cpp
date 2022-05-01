//find total number of components
//print each component
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int visited[N];
vector<vector<int>>cc;
vector<int> current_cc;
void dfs(int vertex)
{
    // cout<<vertex<<endl;
    //take action on vertex after entering vertex
    current_cc.push_back(vertex);
    visited[vertex]=true;
    for(int child:g[vertex])
    {
        if(visited[child])
        continue;
        //take action on child node before entering child node
        dfs(child);
        //take action on child after entering the child
    }
    //take action on vertex before exiting vertex
    return;
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
    int ct=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i])
        continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        ct++;//count number of components
    }
    cout<<"Total number of components are "<<ct<<endl;//cc.size() gives same output
    printf("Each component:-\n");
    for(vector<int> v:cc)
    {
        for(int t:v)
        cout<<t<<" ";
        cout<<"\n";
    }
}
// 8 5
// 1 2 
// 2 3
// 2 4
// 3 5
// 6 7


//vertex 8 is not mentioned but it is there
//answer is 3