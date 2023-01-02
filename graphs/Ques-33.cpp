#include <bits/stdc++.h>
using namespace std;

bool dfs(int arr[],int N,int steps,int currStep,int weights[],int residue)
{
    if(currStep>steps)
     return true;

    for(int i=0;i<N;i++)
    {
      if(arr[i]>residue && arr[i]!=weights[currStep-1])
      {
        weights[currStep]=arr[i];
        residue=arr[i]-residue;
        if(dfs(arr,N,steps,currStep+1,weights,residue))
         return true;

      }
    }
    return false;

}

void printWeightsOnScale(int arr[],int N,int steps)
{
    int currStep=0;
    int weights[steps];
    if(dfs(arr,N,steps,currStep,weights,0))
    {
        for(int i=0;i<steps;i++)
        {
            cout<<weights[i]<<"\t";
        }
    }

    else
     cout<<"Not Possible";
}

int main()
{
    int arr[]={2,3,5,6};
    int N=sizeof(arr)/sizeof(arr[0]);

    int steps=10;
    printWeightsOnScale(arr,N,steps);
}