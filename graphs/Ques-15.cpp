#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:
    map<int,bool> visited;
    map<int,list<int>> graph;
    int V;

    Graph(int V)
    {
        this->V=V;
    }

    void addEdge(int u,int w)
    {
        graph[u].push_back(w);

    }

    void DFS(int u)
    {
        visited[u] = true;
        for(auto it : graph[u])
        {
            if(!visited[it])
            {
                visited[it] = true;
                DFS(it);
            }
        }

    }

    void count_trees()
    {
        int count=0;
        for(auto i : graph)
        {
            if(!visited[i.first])
            {
                count++;
                DFS(i.first);
            }
        }
        cout<<count;
    }

};


int main()
{
   Graph g(5);
   g.addEdge(0,1);
   g.addEdge(0,2);
   g.addEdge(3,4);
   g.addEdge(4,5);
   g.addEdge(6,7);
   g.count_trees(); 
}