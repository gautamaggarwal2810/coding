#include <bits/stdc++.h>
using namespace std;

class Graph 
{

public:
   map<int,bool> visited;
   map<int,list<int>> graph;
   list<int> graphQueue;
   vector<int> level;

   void addEdge(int u,int v)
   {
     graph[u].push_back(v);
   }

   int BFS(int u,int l,int V)
   {
     visited[u] = true;
     level[u]=0;
     graphQueue.push_back(u);

     while(!graphQueue.empty())
     {
        int x=graphQueue.front();
        //cout<<x<<"\t";
        graphQueue.pop_front();

        for(auto it : graph[x])
        {
            if(!visited[it])
            {
                visited[it]=true;
                graphQueue.push_back(it);
                level[it]=level[x]+1;
            }

        }
     }

     int count=0;
     for (int i = 0; i < V; i++)
        if (level[i] == l)
            count++;   
      return count;

   }

};


 int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    cout<<g.BFS(0,2,6);
 
}
 