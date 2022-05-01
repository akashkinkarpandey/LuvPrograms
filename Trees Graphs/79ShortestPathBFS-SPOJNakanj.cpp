#include <iostream>
#include <vector>
#include <utility>
#include <queue>
// https://www.spoj.com/problems/NAKANJ/
//solution  acceptd
using namespace std;
const int INF=10000;
int vis[8][8];
int level[8][8];
int getX(string s)
{
    return s[0] - 'a';
}
int getY(string s)
{
    return s[1] - '1';
}
bool isValid(int x, int y)
{
    return (x >= 0 and y >= 0 and x < 8 and y < 8);
}
vector<pair<int, int>> movements = {
    {-1, 2},
    {1, 2},
    {-1, -2},
    {1, -2},
    {2, -1},
    {2, 1},
    {-2, -1},
    {-2, 1}
};
int bfs(string source, string dest)
{
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);
    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    vis[sourceX][sourceY] = 1;
    level[sourceX][sourceY] =0 ;
    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int x = v.first;
        int y = v.second;
        q.pop();
        for(auto movement:movements)
        {
            int childX=movement.first+x;
            int childY=movement.second+y;
            if(!isValid(childX,childY))
                continue;
            if(!vis[childX][childY])
            {
                q.push({childX,childY});
                level[childX][childY]=level[x][y]+1;
                vis[childX][childY]=1;
            }
        }
        if(level[destX][destY]!=INF)
            break;
    }
    return level[destX][destY];
}
void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2)<<endl;
    }
    return 0;
}