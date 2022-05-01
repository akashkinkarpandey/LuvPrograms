#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
int vis[N];
int level[N];
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty())
    {
        int vertex=q.front();
        q.pop();
        cout<<vertex<<" ";
        for(int child:graph[vertex])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[vertex]+1;
            }
        }
    }
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
bfs(1);
cout<<endl;
for(int i=1;i<=n;i++)
{
    cout<<i<<": "<<level[i]<<endl;
}

}