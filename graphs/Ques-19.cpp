#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:
    map<int,bool> visited;
    map<int,list<int>> graph;
    map<int,list<int>> t;

    void addEdge(int u,int w)
    {
        graph[u].push_back(w);

    }

    void add_Edge(int u,int w)
    {
        t[u].push_back(w);

    }

    void transpose_graph()
    {
        for(auto i : graph)
        {
            add_Edge(i.second,i.first);
        }
       
       for(auto it : t)
       {
        cout<<it.first<<it.second;
       }
    }

};

 int main()
 {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 2);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.transpose_graph();

 }