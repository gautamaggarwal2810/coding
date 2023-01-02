#include <bits/stdc++.h>
using namespace std;

const int N=3;
const int M=3;

void DFS(int m,int n,bool visited[][N], int matrix[][N])
{ 
   visited[m][n] = true;

   if(m+1 < M && matrix[m+1][n]<=matrix[m][n] && !visited[m+1][n]) 
      DFS(m+1,n,visited,matrix);


    if(n+1 < N && matrix[m][n+1]<=matrix[m][n] && !visited[m][n+1]) 
      DFS(m,n+1,visited,matrix);

    if(m-1 >= 0 && matrix[m-1][n]<=matrix[m][n] && !visited[m-1][n]) 
      DFS(m-1,n,visited,matrix);

    if(n-1 >= 0 && matrix[m][n-1]<=matrix[m][n] && !visited[m][n-1]) 
      DFS(m,n-1,visited,matrix);

   
}

void printMinSources(int matrix[][N])
{
    bool visited[M][N];
    memset(visited, false , sizeof(visited));
    vector <pair<int,pair<int,int>>> m;

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            m.push_back(make_pair(matrix[i][j],make_pair(i,j)));
        }
    }

    sort(m.begin(),m.end());

    for(int i=m.size()-1;i>=0;i--)
    {
        if(!visited[m[i].second.first][m[i].second.second])
        {
            cout<<m[i].second.first<<" "<<m[i].second.second << endl;
            DFS(m[i].second.first,m[i].second.second,visited,matrix);
        }
    }
}



int main()
{
    int matrices[][N]={{1,2,3},{2,3,1},{1,1,1}};
    printMinSources(matrices);
}