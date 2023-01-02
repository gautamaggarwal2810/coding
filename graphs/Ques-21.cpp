#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:
    map<int,bool> visited;
    map<int,list<int>> graph;
    list<int> graphQueue;
   
    void addEdge(int v, int w)
    {
	    graph[v].push_back(w); 
    }
    
    void build_tree(int parent[],int size)
    {
        int root_index=-1;
        for(int i = 0; i < size;i++)
        {
            if(parent[i] ==-1)
               root_index=i;

            else 
            {
                addEdge(parent[i],i);
                addEdge(i,parent[i]);
            }
        }
        BFS(root_index,size);
    }

    void BFS(int u,int size)
    {
        int height[size];
        memset(height,0,size);

        visited[u]=true;
        graphQueue.push_back(u);

        while(!graphQueue.empty())
        {
            int x=graphQueue.front();
            graphQueue.pop_front();

            for(auto i : graph[x])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    graphQueue.push_back(i);
                    height[i]=height[x]+1;
                }
            }
        }
        cout<<*max_element(height,height+size);
        
    }
};

 int main()
{
    Graph g;
    int parent[] = { -1, 0, 0, 0, 3, 1, 1, 2 };
 
    int n = sizeof(parent) / sizeof(parent[0]);
 
    g.build_tree(parent, n);
}