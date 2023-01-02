#include<bits/stdc++.h>
using namespace std;
#define V 9
typedef pair<int,int> iPair;

/*
class Graph
{
    public:
     int V;
     map<int,list<iPair>> my_graph;

    Graph(int V)
    {
        this->V=V;
    }

    void addEdge(int u,int v,int w)
    {
        my_graph[u].push_back(make_pair(v,w));
        my_graph[v].push_back(make_pair(u,w));
    }

    void Dijkstra(int src)
    {
        priority_queue<iPair,vector<iPair>,greater<iPair>> pq;

        vector<int> dist(V,9999);
        
        pq.push(make_pair(0,src));
        dist[src]=0;

        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();

            for(auto it : my_graph[u])
            {
                int v=it.first;
                int weight=it.second;

                if(dist[v]>dist[u]+weight)
                {
                    dist[v]=dist[u]+weight;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }

        for(int i=0;i<V;i++)
        {
            cout<<i<<"\t"<<dist[i]<<endl;
        }
    }
};


 int main()
 {
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.Dijkstra(0);
 }


*/
int minDistance(int dist[],bool sptSet[])
{
    int min=INT_MAX;
    int min_index;

    for(int i=0;i<V;i++)
    {
        if(!sptSet[i] && dist[i]<=min)
        {
            min=dist[i];
            min_index=i;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}


void dijkstra(int graph[][V],int src)
{
    int dist[V];
    bool sptSet[V];

    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }

    dist[src]=0;

    for(int i=0;i<V-1;i++)
    {
        int u=minDistance(dist,sptSet);
        sptSet[u]=true;
        for(int j=0;j<V;j++)
        {
            if(!sptSet[j] && graph[u][j] && dist[u]!=INT_MAX && dist[j]>dist[u]+graph[u][j])
             dist[j]=dist[u]+graph[u][j];
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[][V]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph,0);
}