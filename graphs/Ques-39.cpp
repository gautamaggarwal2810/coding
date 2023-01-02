#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int x;
    int y;
    int moves; 
};

bool isSafe(int x,int y,int N)
{
    if(x>=1 && x<=N && y>=1 && y<=N)
     return true;
    return false;
}

int bfs(int initial_pos[],int final_pos[],int N)
{
    list<node> graphQueue;
    bool visited[N+1][N+1];
    memset(visited,false,sizeof(visited));

    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    node n={initial_pos[0],initial_pos[1],0};
    graphQueue.push_back(n);
    visited[initial_pos[0]][initial_pos[1]]=true;


    while(!graphQueue.empty())
    {
        node t=graphQueue.front();
        graphQueue.pop_front();

        if(t.x==final_pos[0] && t.y==final_pos[1])
        {
            return t.moves;
        }

        for(int i=0;i<8;i++)
        {
           int x=t.x+dx[i];
           int y=t.y+dy[i];

           if(isSafe(x,y,N) && visited[x][y]==false)
           {
            visited[x][y]=true;
            graphQueue.push_back({x,y,t.moves+1});
           }
        }

    }
}

int main()
{
    int N = 30;
    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    cout << bfs(knightPos, targetPos, N);
    return 0;
}