#include <bits/stdc++.h>
using namespace std;

void DFS(int vertex[],map<int,list<int>> graph,int N,int parent,int edge1,int edge2,int totalSum,int &sum,int &min,bool visited[])
{
   visited[edge1] = true;
   for(auto it : graph[edge1])
    {
        if(it!=parent && it!=edge2 && !visited[it])
        {
          //neigh.insert(it);
          sum=sum+vertex[it];
          ///cout<<vertex[it]<<endl;
           DFS(vertex,graph,N,edge1,it,edge2,totalSum,sum,min,visited);
           
           //cout<<sum<<"\t"<<it<<endl;
        }
    }


}

int getMinSubtreeSumDifference(int vertex[],int edges[][2],int N)
{
    map<int,list<int>> graph;
    

    for(int i=0;i<N;i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);    
    }

    int totalSum = 0;
    for (int i = 0; i < N; i++)
    {
        totalSum += vertex[i];
    }
    int min=INT_MAX;
    int sum=0;
    bool visited[N];
    for (int i = 0; i < N; i++)
    {
        int sum=vertex[edges[i][0]];
        //set<int> neigh;
       // cout<<sum<<endl;
        
        memset(visited, false, sizeof(visited));
        DFS(vertex,graph,N,-1,edges[i][0],edges[i][1],totalSum,sum,min,visited);
        //cout<<(totalSum-2*sum)<<endl;
        if(min>abs(totalSum-2*sum))
        {
            //cout<<min<<endl;
            min=abs(totalSum-2*sum);
        }
        

    }

    return min;

}



int main()
{
    int vertex[] = {4, 2, 1, 6, 3, 5, 2};
    int edges[][2] = {{0, 1}, {0, 2}, {0, 3},
                    {2, 4}, {2, 5}, {3, 6}};
    int N = sizeof(vertex) / sizeof(vertex[0]);
 
    cout << getMinSubtreeSumDifference(vertex, edges, N);
}