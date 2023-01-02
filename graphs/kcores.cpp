#include<bits/stdc++.h>
using namespace std;

class Graph {
 
 public: 
 
 map<int,bool> visited;
 map<int,list<int>> graph;
 list<int> graphQueue;
 int V;
 
 Graph(int V)
 {
    this->V = V;
 }

 void addEdge(int u,int v)
 {
    graph[u].push_back(v);
 }

 bool DFS_Util(int start_degree,vector<int> &vDegree,int k)
 {
    visited[start_degree] = true;

    for(auto i : graph[start_degree])
    {
        if(vDegree[start_degree]<k)
          vDegree[i]--;
        
        if(!visited[i])
        {
            DFS_Util(i,vDegree,k);
        }
    }
    return (vDegree[start_degree] < k);
 }


 void printKcores(int k)
 {
    for(auto it : graph)
    {
        visited[it.first]=false;
    }
    int min_degree=INT16_MAX;
    int start_degree=INT16_MAX;
    vector<int> vDegree(V);

    for(int i=0;i<V;i++)
    {
        vDegree[i]=graph[i].size();
        if(vDegree[i]<min_degree)
        {
            min_degree=vDegree[i];
            start_degree=i;
        }
    }

    DFS_Util(start_degree,vDegree,k);
    for (int i=0; i<V; i++)
        if (visited[i] == false)
            DFS_Util(i,vDegree,k);
   
    
    for (int v=0; v<V; v++)
    {
        if (vDegree[v] >= k)
        {
            cout << "\n[" << v << "]";
            for(auto i : graph[v]){
                if(vDegree[i] >= k)
                 cout << " -> " << i;
            }
            
        }
    }
 }


};


 int main(){
    int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKcores(k);
 }