#include <bits/stdc++.h>
using namespace std;

class Graph{

public: 
 int visited[5][5];

 Graph()
 {
    memset(visited,0,sizeof(visited));
 }

 void DFS(int u,int v,int m,int n)
 {
    visited[u][v] =1;
    
    if(u+1<m && visited[u+1][v]==0)
     DFS(u+1,v,m,n);

    if(v+1<n && visited[u][v+1]==0)
     DFS(u,v+1,m,n);

    if(u-1>0 && visited[u-1][v]==0)
     DFS(u-1,v,m,n);

    if(v-1>0 && visited[u][v-1]==0)
     DFS(u,v-1,m,n);
 }
 
 

 int isPossible(int m,int n,int k,int r,vector<int> X,vector<int> Y)
 {

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int p=0;p<k;p++)
            {
                if(sqrt(pow(X[p]-i-1,2)+pow(Y[p]-j-1,2))<=r)
                {
                    visited[i][j] =-1;
                }
            }
        }
    }

    if(visited[0][0]==-1)
     return 0;
    
    DFS(0,0,m,n);

    if(visited[m-1][n-1]==1)
    {
        return 1;
    }

    else 
     return 0;
 }

};
int main()
{
    Graph g;
    int m1 = 5, n1 = 5, k1 = 2, r1 = 1;
    vector<int> X1 = { 1, 3 };
    vector<int> Y1 = { 3, 3 };
    if (g.isPossible(m1, n1, k1, r1, X1, Y1))
        cout << "Possible" << endl;
    else
        cout << "Not Possible" << endl;
}