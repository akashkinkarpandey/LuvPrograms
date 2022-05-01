// https://www.interviewbit.com/problems/delete-edge/
//submitted
#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
void dfs(int vertex,int par,vector<int>g[],vector<int>&sub_tree,vector<int>&val)
{
    // cout << vertex << endl;
    //take action on vertex after entering vertex
    sub_tree[vertex]=sub_tree[vertex]+val[vertex-1];
    for(int child : g[vertex])
    {
        if (child == par)
            continue;
        //take action on child node before entering child node
        dfs(child, vertex,g,sub_tree,val);
        sub_tree[vertex]=sub_tree[vertex]+sub_tree[child];
        //take action on child after entering the child
    }
    //take action on vertex before exiting vertex
    return;
}
class Solution
{
    int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<int>g[A.size()+1];//graph list
    vector<int>sub_tree(A.size()+1,0);
    for(auto edge:B)
    {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }
    dfs(1,-1,g,sub_tree,A);
    long long ans=0;
    for(int i=2;i<=A.size();i++)
    {
        int part1=sub_tree[i];
        int part2=sub_tree[1]-part1;
        ans=max(ans,(part1*1LL*part2)%M);
    }
    return ans;
}
};