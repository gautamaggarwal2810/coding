#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph[],int N,bool visited[],int u,int &k)
{
    visited[u]=true;

    for(auto i :graph[u])
    {
        if(!visited[i])
        {
            k++;
            visited[i]=true;
            DFS(graph,N,visited,i,k);
        }
    }


}

int count(vector<int> graph[],int N)
{
    bool visited[N*N+N];
    memset(visited,false,sizeof(visited));
    int ans=0;


    for(int i=0;i<N*N;i++)
    { 
        int k=1;
        DFS(graph,N,visited,it,k);
        ans=ans+k*(N*N-k);
    }
    
    return ans;


}



void insert_path(vector<int> graph[],int N,int x1,int y1,int x2,int y2)
{
    int a=(x1-1)*N+y1;
    int b=(x2-1)*N+y2;

    graph[a].push_back(b);
    graph[b].push_back(a);

}


int main()
{
    int N = 2;
 
    vector<int> graph[N*N + 1];

    insert_path(graph, N, 1, 1, 1, 2);
    insert_path(graph, N, 1, 2, 2, 2);

    cout<<count(graph,N);


}