#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public: 

    int V;
    map<int,list<int>> graph;
    map<int,bool> visited;
    list<int> graphQueue;
    map<int,list<int>> heights;

    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u,int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void BFS(int u)
    {
        int height[V];
        memset(height,0,sizeof(height));

        for(auto i : visited)
        {
            visited[i.first]=false;
        }

        height[u]=0;
        visited[u] = true;
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

        int index=0;
        //int h=0;

        for(int i=0;i<V;i++)
        {
            if(height[i]>height[index])
            {
                index=i;
                //cout<<height[index]<<endl;
            }
        }
       // cout<<index<<endl;
        heights[height[index]].push_back(u);

    }

    void min_height()
    {
        int min=INT_MAX;
        for(auto i : heights)
        {
            if(i.first<min)
            {
                min=i.first;
               // cout<<"min is : "<<min;
            }
        }

        for(auto i : heights[min])
        {
            cout<<i<<endl;
        }
    }





};

int main()
{
    Graph g(6);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(5, 4);

    for(int i=0;i<6;i++)
    {
        g.BFS(i);
        //cout<<"Hi"<<i<<endl;
    }

    g.min_height();

}
