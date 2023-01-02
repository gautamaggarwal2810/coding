#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int index;
    int path;
};


int BFS(map<int,list<int>> graph,int N)
{
    bool visited[N];
    memset(visited,false,sizeof(visited));

    list<node> graphQueue;
    graphQueue.push_back({0,0});
    
    visited[0] = true;

    while(!graphQueue.empty()) 
    {
        node t=graphQueue.front();
        graphQueue.pop_front();

        if(t.index==N-1)
        {
            return t.path;
        }

        for(auto i : graph[t.index])
        {
            if(!visited[i])
            {
                visited[i]=true;
                graphQueue.push_back({i,t.path+1});
            }

        }

    }
    return 0;


}

void create_graph(int arr[],int N)
{
    map<int,list<int>> graph;

    for(int i=1;i<N-1;i++)
    {
        graph[i].push_back(i+1);
        graph[i].push_back(i-1);
    }
    graph[0].push_back(1);
    graph[N-1].push_back(N-2);

    map<int,list<int>> look_ahead;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(arr[i]==arr[j])
             look_ahead[i].push_back(j);
        }
    }

    for(int i=0;i<N;i++)
    {
        for(auto it : look_ahead[i])
    {
       graph[i].push_back(it);
       graph[it].push_back(i);
    }
    }

    cout<<BFS(graph,N);
}



int main()
{
    int arr[] = {5, 4, 2, 5, 0};
    int N = sizeof(arr) / sizeof(int);
    create_graph(arr, N);
    return 0;
}