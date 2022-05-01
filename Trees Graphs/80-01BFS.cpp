// https://www.codechef.com/problems/REVERSE
//solution accepted
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
//visited array not required in 0-1 BFS
//queue stores nodes of atmost two levels at a particular time
//0-weights inserted at queue front to be treated like previous level nodes
//1-weights inserted at queue back to be treated like next level nodes
//djikstra type algorithm(works a bit better in terms of time complexity)
const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>>g[N];
vector<int>lev(N,INF);
int n,m;
int bfs()
{
    deque<int>q;
    q.push_back(1);
    lev[1]=0;
    while(!q.empty())
    {
        int cur_v=q.front();
        q.pop_front();
        for(auto child:g[cur_v])
        {
            int child_v=child.first;
            int wt=child.second;
            if(lev[cur_v]+wt<lev[child_v])
            {
                lev[child_v]=lev[cur_v]+wt;
                if(wt==1)
                q.push_back(child_v);
                else 
                q.push_front(child_v);
            }
        }
    }
    if(lev[n]==INF) return -1;
    return lev[n];
}
int main()
{
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int x,y;
    cin>>x>>y;
    g[x].push_back({y,0});
    g[y].push_back({x,1});
    if(x==y)continue;
}
cout<<bfs()<<endl;
return 0;
}