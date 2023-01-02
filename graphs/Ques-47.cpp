#include<bits/stdc++.h>
using namespace std;

class Graph 
{
  public:
	map<int, bool> visited;
	map<int, list<int> > graph;
    int V;

    Graph(int V)
    {
        this->V=V;
    }

    void addEdge(int u,int w)
    {
        graph[u].push_back(w);
    }

    bool BFS(int u,int v,int root)
    {
       list<int> graphQueue;
       for(auto i : visited)
       {
            visited[i.first]=false;
       }
       
       visited[u] = true;
       graphQueue.push_back(u);
       
       if(u==root)
        return true;
       
       while(!graphQueue.empty())
       {
        int x=graphQueue.front();
        graphQueue.pop_front();
        //parent=x;

        if(x==v)
        {
            return true;
        }

        for(auto i : graph[x])
        {
            if(!visited[i] && i!=root)
            {
                visited[i]=true;
                graphQueue.push_back(i);
            }
        }

       }
       return false;

    }

};

int main()
{
    Graph g(9);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,6);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(5,7);
    g.addEdge(5,8);
    g.addEdge(5,9);

    cout<<g.BFS(1,5,1);
    cout<<g.BFS(5,7,1);
    cout<<g.BFS(2,6,1);
}