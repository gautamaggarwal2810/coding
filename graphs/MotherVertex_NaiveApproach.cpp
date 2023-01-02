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
        //cout<<u<<"\t";

        for(auto it : graph[u])
        {
            if(!visited[it])
            {
                DFS(it);
            }
        }
    }

    int motherVertex(int u , int V)
    {
        int number_of_Vertices_Visited=0;
        for(auto it : graph)
        {
            visited[it.first]=false;
        }

        DFS(u);

       for(int i=0 ; i<V ; i++)
       {
        if(visited[i])
          number_of_Vertices_Visited++;
       }
       
       if ( number_of_Vertices_Visited==V )
         return u;
       else if(u+1<=V)
        motherVertex(u+1,V);
       else 
        return -1;    
    }

};


int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
    int x=g.motherVertex(0,g.graph.size());
    //cout<<x;
    if(x!=-1)
    {
        cout << "Mother Vertex exists"<<":"<<x;
    }
}