#include <bits/stdc++.h>
using namespace std;

class Graph {

 public:
    map<int,bool> visited;
    map<int,list<int>> graph;
    int V;

    Graph(int V)
    {
       this->V=V; 
    }

    void add_edge(int u,int w)
    {
        graph[u].push_back(w);

    }

    int count_p(int s , int d)
    {
        int count=0;
        count_paths(s,d,count); 
        return count;
    }

    void count_paths(int s , int d ,int &count)
    {
        //int count=0;
        visited[s]=true;
        //cout<<s;

        if(s==d)
        {
            count++;
        }
        else
        {
            for(auto i : graph[s])
            {
                if(!visited[i])
                count_paths(i,d,count);
            }
        }

        visited[s]=false;
    }
};

 int main()
{
    
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(2, 1);
    g.add_edge(3, 2);
     
     
    cout << g.count_p(0,4);
 
    return 0;
}