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
        graph[w].push_back(u);
        

    }

    void DFS(int u,int v)
    {
        int count=0;
        visited[u] = true;
        if(u==v)
        {
            cout<< count;
        }
        else {
        for(auto i : graph[u])
        {
            if(!visited[i])
            {
                 count++;
                 //cout<<i<<endl<<v<<endl;
                 DFS(i,v);

            }
        }
        }
       // return 0;
       
    }

    //int bfs(int u,int v);
};

    bool compare(int x,int y)
    {
        string X=to_string(x);
        string Y=to_string(y);
        
        int digit=0;

        if(X[0]!=Y[0])
           digit++;

        if(X[1]!=Y[1])
           digit++;
        
        if(X[2]!=Y[2])
           digit++;

        if(X[3]!=Y[3])
           digit++;

        return (digit==1);
    }

    void SieveOfEratosthenes(vector<int> &v)
    {
        int n=9999;
        bool p[n+1];
        memset(p,true,sizeof(p));

        for(int i=2;i*i<=n;i++)
        {
            if(p[i]==true)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    p[j]=false;
                }
            }
        }

        for(int i=1000;i<=n;i++)
        {
            if (p[i]==true)
                 v.push_back(i);
        }

    }


    int shortest_path(int num1,int num2)
    {
        int index1=-1,index2=-1;
        vector<int> prime;

        SieveOfEratosthenes(prime);

        Graph g(prime.size());
        for(int i=0;i<prime.size();i++)
        {
            for(int j=i+1;j<prime.size();j++)
            {
                if(compare(prime[i],prime[j]))
                 g.addEdge(i,j);
            }
        }

        for(int i=0;i<prime.size();i++)
         if(prime[i]==num1)
          index1=i;

        for(int i=0;i<prime.size();i++)
         if(prime[i]==num2)
          index2=i;
        cout<<prime[858];
        g.DFS(index1,index2);
    }


  int main()
{
    int num1 = 1033, num2 = 8179;
    cout << shortest_path(num1, num2);
    return 0;
}
