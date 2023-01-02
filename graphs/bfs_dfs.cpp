#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > graph;
    list<int> graphQueue; // Only for BFS

void addEdge(int v, int w)
{
	graph[v].push_back(w); 
}

void BFS(int v)
{

    visited[v] = true;
    graphQueue.push_back(v);  

    while(!graphQueue.empty()){
        int x = graphQueue.front();
        cout << x << endl;
        graphQueue.pop_front();

        for(auto i = graph[x].begin(); i != graph[x].end(); ++i){
           if(!visited[*i]){
            visited[*i] = true;
            graphQueue.push_back(*i);
           }
        }
    }

}


void DFS(int v)
{	
	visited[v] = true;
	cout << v << " ";
	
	for (auto i = graph[v].begin(); i != graph[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

 void BFS_DFS_Disconnected(){
    for(auto i : graph ){
        if(visited[i.first] == false ){
            BFS(i.first);
        }
    }
}
};

int main()
{
	
	Graph g;
	g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
   // g.DFS_Disconnected();
    g.BFS_DFS_Disconnected();
	return 0;
}


