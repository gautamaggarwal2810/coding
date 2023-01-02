#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:
    map<int,bool> visited;
    map<int,list<int>> graph;
    list<int> graphQueue;
    int V;

    Graph(int V)
    {
        this->V=V;
    }

    void addEdge(int u,int w)
    {
        graph[u].push_back(w);
        graph[w].push_back(u);
    }

    void BFS(int u,int d)
    {
        int *distance=new int[V];
        memset(distance,0,sizeof(distance));

        visited[u] = true;
        distance[u]=0;
        graphQueue.push_back(u);

        while(!graphQueue.empty())
        {
            int x=graphQueue.front();
            graphQueue.pop_front();
            for(auto it : graph[x])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    graphQueue.push_back(it);
                    distance[it]=distance[x]+1;
                }

            }
        }
        cout<<distance[d];
    }
};

 int main()
 {
    Graph g(9);
    
    g.addEdge( 0, 1);
    g.addEdge( 0, 7);
    g.addEdge( 1, 7);
    g.addEdge( 1, 2);
    g.addEdge( 2, 3);
    g.addEdge( 2, 5);
    g.addEdge( 2, 8);
    g.addEdge( 3, 4);
    g.addEdge( 3, 5);
    g.addEdge( 4, 5);
    g.addEdge( 5, 6);
    g.addEdge( 6, 7);
    g.addEdge( 7, 8);

    g.BFS(0,5);
 }