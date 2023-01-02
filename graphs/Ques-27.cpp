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

    void addEdge(int u,int w)
    {
        graph[u].push_back(w);
    }

    void print_all(int s , int d)
    {
        vector<int> path;

        print_all_paths(s,d,path);
    }

    void print_all_paths(int u,int d,vector<int> path)
    {
        visited[u]=true;
        path.push_back(u);

        if(u==d)
        {
            for (int i = 0; i < path.size(); i++)
              cout << path[i] << " ";
            cout << endl;
        }

        else
        {
            for(auto i : graph[u])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    print_all_paths(i,d,path);
                }
            }
        }

        visited[u]=false;
        path.pop_back();
    }

};

 int main()
 {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
 
    int s = 2, d = 3;
    cout << "Following are all different paths from " << s<< " to " << d << endl;
    g.print_all(s, d);
 }