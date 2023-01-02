#include<bits/stdc++.h>
using namespace std;

class Graph 
{

public:
       map<int,bool> visited;
       map<int,list<int>> graph;
       list<int> graphQueue;
    
    void addEdge(int u,int v)
    {
        graph[u].push_back(v);
    }

    void printt()
    {
        int i=0;
        while(i<graph.size())
      {
        for(auto it : graph[i])
      {
        cout<<i<<it<<endl;
      }
      i++;
      }
     }

};


int main()
{
    int i=0;
    Graph G;
    vector<vector<int>> g={{1},{0,2,4},{1,3,4},{2},{1,2}};
    while(i<int(g.size()))
    {
        for(auto it : g[i])
      {
        G.addEdge(i,it);
      }
      i++;
    }

    G.printt();
}