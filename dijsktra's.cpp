#include <bits/stdc++.h>
using namespace std;


int getMinVertex(bool *visited,int *weight,int n)
{
    int minVertex=-1;

    for(int i=0;i<n;i++)
    {
        if(!(visited[i]) && ((minVertex==-1)|| ( weight[minVertex]> weight[i] )   ))
          minVertex=i;


    }

    return minVertex;



}



void djikstra(int **edges,int n)
{
  bool *visited=new bool[n]();
    int *weight=new int[n];
    


    for(int i=0;i<n;i++)
        weight[i]=INT_MAX;
    weight[0]=0;
    



    for(int i=0;i<n-1;i++)
    {
        int minVertex=getMinVertex(visited,weight,n);

        visited[minVertex]=true;

        for(int j=0;j<n;j++)
        {  if(  edges [minVertex][j] !=0 && !visited[j] )
        {
            if(weight[j]>weight[minVertex] + edges[minVertex][j])
            {  weight[j]=edges[minVertex][j]+ weight[minVertex];
              

            }
        }



        }



    }

    for(int i=0;i<n;i++)
    {  
      cout<<i<<" "<<weight[i]<<endl;

    }







}



int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  int **edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }


        for(int j=0;j<E;j++)
        {   int a,b,c;
            cin>>a>>b>>c;
            edges[a][b]=c;
            edges[b][a]=c;
        }

    djikstra(edges,V);








  return 0;
}
