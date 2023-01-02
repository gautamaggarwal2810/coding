#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:

    map<int,bool> visited;
    map<int,list<int>> graph;
    bool** tc;
    int V;

    Graph(int V)
    {
        this->V = V;
        tc=new bool*[V];
        for(int i=0; i<V; i++)
        {
            tc[i]=new bool[V];
        }

        for (int i = 0; i < V; i++)
        {
          for (int j = 0; j < V; j++) 
          {
            tc[i][j] = false;
          }
        }

    }

    void addEdge(int u,int w)
    {
        graph[u].push_back(w);

    }

    void DFS_Util(int s,int v)
    {
        tc[s][v]=true;
        for(auto i : graph[v])
        {
            if(tc[s][i]==false)
            {
                if(s==i)
                {
                    tc[s][i]=true;
                }
                else
                    DFS_Util(s,i);
            }
        }
    }

    void transitive_closure()
    {
        for (int i = 0; i < V; i++)
        {
            DFS_Util(i,i);
        }

        for (int i = 0; i < V; i++)
        {
          for (int j = 0; j < V; j++) 
          {
            cout<<tc[i][j]<<" ";
          }
          cout<<endl;
        }
    }


};

 int main()
{
 
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Transitive closure matrix is \n";
    g.transitive_closure();
    return 0;
}
