#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int initialColor;
    int newCol;
public:
    void dfs(int i,int j,vector<vector<int>> &image)
    {
        int r=image.size();
        int c=image[0].size();
        if(i<0 || j<0) return;
        if(i>=r || j>=c) return;
        if(image[i][j]!=initialColor) return;
        image[i][j]=newCol;
        dfs(i-1,j,image);
        dfs(i+1,j,image);
        dfs(i,j+1,image);
        dfs(i,j-1,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        initialColor=image[sr][sc];
        newCol=newColor;
        if(initialColor!=newColor)
            dfs(sr,sc,image);
        return image;
    }
};