//DFS based

#include<iostream>
using namespace std;


#define lim 100
int array[lim];
int V,E;





class stack1{
   int front;
  int size;

  public:
    stack1()
    {
      front=0;
      size=0;
      for(int i=0;i<100;i++)
        array[i]=-1;
    }

  void push(int x)
  {
    array[front]=x;
     front=front+1;
    size++;
  }

  int pop()
  {
    size--;
    front=front-1;
    return array[front];
  }
  bool empty()
  {
    if(size==0)
      return false;
    else
      true;
      }
  };









// A recursive function used by topologicalSort
topologicalSortUtil(int v, bool visited[],
                                stack1 &Stack,int **adj)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex

    for (int i=0;i<V;i++)
    {

        if(adj[v][i]==1)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack,adj);
    }
    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void topologicalSort(int **adj)
{
    stack1 Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack,adj);

    // Print contents of stack
    while (Stack.empty() == true)
    {
        cout << Stack.pop() << " ";

    }
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram

    cin>>V>>E;
    int **adj=new  int*[lim];

 for(int k=0;k<100;k++)
{
    adj[k]=new int[lim];
    for(int j=0;j<100;j++)
        adj[k][j]=0;
}

    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x][y]=1;

    }


    cout << "Following is a Topological Sort of the given graph \n";
    topologicalSort(adj);

    return 0;
}









