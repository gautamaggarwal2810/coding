#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:
    map<int,bool> visited;
    map<int,list<int>> graph;
    list<int> graphQueue;
    int V;

    Graph(int V)
    {
        this->V=V;
    }

    void addEdge(int u,int w)
    {
        graph[u].push_back(w);
        graph[w].push_back(u);
    }

    void count_nodes(int marked[],int K,int n)
    {
        
        vector<int> m;

        for(int i=0;i<n;i++)
        {
            BFS(marked[i],m,K,i);
        }

        for(int i=0;i<m.size();i++)
        {
            cout<<m[i]<<" ";
            //cout<<"Empty";
        }

    }

    void BFS(int u,vector<int> &m,int K,int index)
    {
        for(auto i : visited)
        {
            visited[i.first]=false;
        }

        int* distance=new int[V];
        memset(distance,0,sizeof(distance));

        distance[u]=0;
        visited[u]=true;
        graphQueue.push_back(u);

        while(!graphQueue.empty())
        {
            int x = graphQueue.front();
            //cout<<x<<"\t";
            graphQueue.pop_front();

            for(auto it : graph[x])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    graphQueue.push_back(it);
                    distance[it]=distance[x]+1;
                }
            }
        }

        if(index==0)
        {
            for(int i=0;i<V;i++)
            {
                if(distance[i]<=K)
                {
                    m.push_back(i);
                }
            }
        }

        else
        {
            int i=0;
            while(i<m.size())
            {
                if(distance[m[i]]>K)
                  m.erase(m.begin()+i);
                i++;   
            }  
        }
        



    }
};

int main()
{
    Graph g(10);
    g.addEdge(1,0);
    g.addEdge(0,3);
    g.addEdge(0,8);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(3,7);
    g.addEdge(4,5);
    g.addEdge(5,9);

    int K=3;
    int marked[]={1,2,4};
    int n=sizeof(marked)/sizeof(marked[0]);

    g.count_nodes(marked,K,n);
}