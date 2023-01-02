#include <bits/stdc++.h>
using namespace std;
#define N 3
struct node 
{
  int x;
  int y;
  int path;
};
//int N=4;
struct node find_src(int M[][N])
{
    struct node src;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(M[i][j]==1)
            {
             src={i,j,0};
            }
        }
    }

    return src;
}

struct node find_dest(int M[][N])
{
    struct node dest;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(M[i][j]==2)
            {
               dest={i,j,0};
               //cout<<i<<"\t"<<j <<endl;
            }
        }
    }
    return dest;
}

bool isSafe(int x,int y)
{
  if(x>=0 && x<N && y>=0 && y<N)
   return true;
  return false;
}

void DFS(node n,node dest,int M[N][N],bool visited[][N],vector<int> &path)
{
  visited[n.x][n.y]=true;

  if(n.x==dest.x && n.y==dest.y)
  {
    cout<<n.x<<n.y;
    path.push_back(n.path);
    visited[n.x][n.y]=false;
    return ;
  }

  else
  { 
    cout<<n.x<<n.y<<endl;
    if(isSafe(n.x+1,n.y) && !visited[n.x+1][n.y] && M[n.x+1][n.y]!=0)
     DFS({n.x+1,n.y,n.path+1},dest,M,visited,path);

    if(isSafe(n.x,n.y+1) && !visited[n.x][n.y+1] && M[n.x][n.y+1]!=0)
     DFS({n.x,n.y+1,n.path+1},dest,M,visited,path);

    if(isSafe(n.x-1,n.y) && !visited[n.x-1][n.y] && M[n.x-1][n.y]!=0)
     DFS({n.x-1,n.y,n.path+1},dest,M,visited,path);

   if(isSafe(n.x,n.y-1) && !visited[n.x][n.y-1] && M[n.x][n.y-1]!=0)
     DFS({n.x,n.y-1,n.path+1},dest,M,visited,path); 
  }


}

void count_min(int M[][N])
{
  //int min_path=0;
  bool visited[N][N];
  memset(visited,false,sizeof(visited));

  struct node src=find_src(M);
  struct node dest=find_dest(M);

  vector<int> path;

  DFS(src,dest,M,visited,path);
  cout<<*min_element(path.begin(),path.end());

}

int main()
{
 // int N=4;
  int M[N][N] = {{ 0 , 3 , 2 },
                   { 3 , 3 , 0 },
                   { 1 , 3 , 0 }};
    

    count_min(M);



}