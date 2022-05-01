#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
// adjacency matrix

//unweighted undirected graphs
int graph1[N][N];
//weighted undirected graphs
int graph3[N][N];

//adjaceny list

//unweighted undirected graphs
//array of vector
vector<int> graph2[N];
//weighted undirected graphs
vector<pair<int, int>> graph4[N];

int main()
{
    int n, m;
    //vertices,edges
    cin >> n >> m;
    //int graph1[n+1][n+1]->if declared locally
    //non weighted edges
    {
        for (int i = 0; i < m; i++)
        {
            //configuration of edges
            int v1, v2;
            cin >> v1 >> v2;
            
            //adjaceny matrix
            graph1[v1][v2] = 1;
            graph1[v2][v1] = 1;
            
            //adjacency list
            graph2[v1].push_back(v2);
            graph2[v2].push_back(v1);
        }
    }

    //weighted edges
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int v1, v2, wt;
            cin >> v1 >> v2 >> wt;
            //adjaceny matrix

            graph3[v1][v2] = wt;
            graph3[v2][v1] = wt;
            //adjacency list

            graph4[v1].push_back({v2, wt});
            graph4[v2].push_back({v1, wt});
        }
    }
}

//input

//unweighted input

// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6

//weighted input

// 6 9 
// 1 3 4
// 1 5 3
// 3 5 2
// 3 4 7
// 3 6 8
// 3 2 9
// 2 6 1
// 4 6 2
// 5 6 3

