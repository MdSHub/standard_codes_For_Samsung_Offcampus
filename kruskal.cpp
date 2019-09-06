#include<bits/stdc++.h>
using namespace std;
class edge
{  public:
    int s;
    int d;
    int w;

};



bool compare(edge e1,edge e2)
{

    return e1.w<e2.w;
}

int getparent(int *parent,int v)
{  
    
   
    while(v!=parent[v])
        v=parent[v];
    
    return v;
}


edge* kruskal(edge *edges,int n,int  e)
{
    edge *output=new edge[n-1];

    sort(edges,edges+e,compare);
    int count=0;
    int *parent=new int[n];
    for(int  i=0;i<n;i++)
        parent[i]=i;
        int i=0;
    while(count<n-1)
    {
        edge ce=edges[i];
        
        int cesp=getparent(parent,ce.s);
        int cedp=getparent(parent,ce.d);

        if(cesp!=cedp)
        {
            output[count]=ce;
            count++;
            parent[cesp]=cedp;
        }


        i++;
  
    }





   return output;






}


int main()
{
    int n,e;
    cin>>n>>e;
    edge *edges=new edge[e];

    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges[i].s=a;
        edges[i].d=b;
        edges[i].w=c;
    }

   edge *output=kruskal(edges,n,e);

    for(int i=0;i<n-1;i++)
    {
        if(output[i].s<output[i].d)
            cout<<output[i].s<<" "<<output[i].d<<" "<<output[i].w<<endl;
        else
             cout<<output[i].d<<" "<<output[i].s<<" "<<output[i].w<<endl;

    }


    return 0;
}
