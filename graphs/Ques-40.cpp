#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int value;
    int level; 
};

int bfs(int x,int y)
{
    set<int> visited;
    list<node> graphQueue;

    node n={x,0};

    //visited[x]=1;
    graphQueue.push_back(n);

    while(!graphQueue.empty())
    {
        node t=graphQueue.front();
        graphQueue.pop_front();

        if(t.value==y)
        {
            return t.level;
        }

        visited.insert(t.value);

        if(2*t.value==y || t.value-1==y)
        {
            return t.level+1;
        }

        if(visited.find(2*t.value)==visited.end())
        {
            graphQueue.push_back({2*t.value,t.level+1});
        }

        if(visited.find(t.value-1)==visited.end())
        {
            graphQueue.push_back({t.value-1,t.level+1});
        }
    }
}

int main()
{
    int x = 4, y = 7;
    cout << bfs(x, y);
    return 0;
}