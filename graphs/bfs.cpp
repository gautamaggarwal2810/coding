#include <bits/stdc++.h>
using namespace std;

class Graph {

public:
       map<int,bool> visited;
       map<int,list<int>> graph;
       list<int> graphQueue;
    
    void addEdge(int u,int v)
    {
        graph[u].push_back(v);
    }

    void BFS(int u)
    {
        visited[u]=true;
        graphQueue.push_back(u);

        while(!graphQueue.empty()){
            int x = graphQueue.front();
            cout<<x<<"\t";
            graphQueue.pop_front();

            for(auto it : graph[x])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    graphQueue.push_back(it);
                }

            }
        }

        for(auto y : graph)
        {
            if(!visited[y.first])
            {
                BFS(y.first);
            }
        }
    }     

};


 int main(){
    Graph g;
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.BFS(0);
 }