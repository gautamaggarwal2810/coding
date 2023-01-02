#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:
    map<int,bool> visited;
    map<int,list<int>> graph;
    int count1=0,count2=0;

    void addEdge(int v, int w)
    {
	    graph[v].push_back(w);
        //graph[w].push_back(v);  
    }

    void DFS(int u,int colour)
    {
        if(colour==0)
         count1++;
        else 
         count2++;

        visited[u]=true;

        for(auto i : graph[u])
        {
            if(!visited[i])
            {
                DFS(i,!colour);
            }
        }
    }

   

    void getEdgeCount(int n)
    {
        DFS(1,0);
        cout<<(count1*count2-n+1);

    }

};

 int main()
 {
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.getEdgeCount(5);
 }

