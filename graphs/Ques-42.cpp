#include <bits/stdc++.h>
using namespace std;

int mod(string t, int N)
{
   int num=stoi(t);
   return num%N;
}

string getMinimumMultipleOfBinaryDigit(int N)
{
    list<string> graphQueue;
    set<string> visited;

    string t="1";
   
    graphQueue.push_back(t);

    while(!graphQueue.empty())
    {
        string t=graphQueue.front();
        graphQueue.pop_front();

        if(!mod(t,N))
         return t;

        else if(visited.find(t) == visited.end())
        {
            visited.insert(t);
            graphQueue.push_back(t+"0");
            graphQueue.push_back(t+"1");
        }
    }
}

int main()
{
    int N = 17;
    cout << getMinimumMultipleOfBinaryDigit(N);
    return 0;
}