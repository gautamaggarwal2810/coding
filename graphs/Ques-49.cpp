#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5


bool isSafe(int M[][COL],int x,int y,bool visited[][COL])
{
    if((x >= 0) && (x < ROW) && (y >= 0) && (y < COL) && (M[x][y] && !visited[x][y]))
     return true;

    return false;
}

void DFS(int x,int y,bool visited[][COL],int M[][COL],int &count)
{
    visited[x][y]=true;

    int dx[]={-1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[]={-1, 0, 1, -1, 1, -1, 0, 1 };

    for(int i=0;i<8;i++)
    {
        if(isSafe(M,x+dx[i],y+dy[i],visited))
        {
            count++;
            DFS(x+dx[i],y+dy[i],visited,M,count);
        }
    }
}

int largestRegion(int M[][COL])
{
    bool visited[ROW][COL];
    memset(visited,false,sizeof(visited));
    vector<int> max;

    for (int i = 0; i < ROW ; i++)
    {
        for (int j = 0; j < COL ; j++)
        {
            if(M[i][j])
            {
                int count=1;
                DFS(i,j,visited,M,count);
                max.push_back(count);
            }
        }
    }

    return *max_element(max.begin(),max.end());

}


int main()
{
    int M[][COL] = { { 0, 0, 1, 1, 0 },
                     { 1, 0, 1, 1, 0 },
                     { 0, 1, 0, 0, 0 },
                     { 0, 0, 0, 0, 1 } };
 
    cout << largestRegion(M);
 
    return 0;
}