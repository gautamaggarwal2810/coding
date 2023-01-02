#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:
    map<int,bool> visited;
    map<int,list<int>> graph;

    void addEdge(int u,int w)
    {
        graph[u].push_back(w);

    }

    void DFS(int u)
    {
        visited[u]=true;
        cout<<u<<"\t";

        for(auto it : graph[u])
        {
            if(!visited[it])
            {
                DFS(it);
            }
        }

        for(auto it : graph)
        {
            if(!visited[it.first])
            {
                DFS(it.first);
            }

        }
    }



};


int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    g.DFS(0);
}