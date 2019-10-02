//DFS based

class Graph 
{ 
    int V;    // No. of vertices' 
  
    // Pointer to an array containing adjacency listsList 
    list<int> *adj; 
  
    // A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);   // Constructor 
  
     // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // prints a Topological Sort of the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[],  
                                stack<int> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. It uses recursive  
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    while (Stack.empty() == false) 
    { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topologicalSort(); 
  
    return 0; 
} 





//2 nd implementation...
#include <iostream>
#include <list>
#include <stack>

using namespace std;
class Graph
{
    int V;
    list <int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u-1].push_back(v-1);
    }
    void TopologySort();
    void TopologySortHelper(int, bool *,stack<int>&Stack);
    void TopologySort2();
};

void Graph::TopologySort()
{
    stack<int>Stack;
    bool *visited = new bool[V];
    for(int i = 0;i<V;i++) visited[i] = false;

    for(int i =0;i<V;i++)
    {
        if(visited[i] == false)
            TopologySortHelper(i,visited,Stack);
    }
    while(!Stack.empty())
    {
        cout<<Stack.top()+1<<" ";
        Stack.pop();
    }
}
void Graph::TopologySortHelper(int v, bool *visited, stack<int>&Stack) {
    visited[v] = true;
    list<int>::iterator i;

    for(i = adj[v].begin();i != adj[v].end();i++)
    {
        if(!visited[*i])
        {
            TopologySortHelper(*i,visited,Stack);
        }
    }
    Stack.push(v);
}
void Graph::TopologySort2() {
    int *indeg = new int[V];
    for(int i =0;i<V;i++) indeg[i] = 0;

    list<int>::iterator j;
    for(int i =0;i<V;i++)
    {
        for(j = adj[i].begin();j!=adj[i].end();j++)
        {
            indeg[*j]++;
        }
    }
    list<int>Q;int s;
    for(int i = 0;i<V;i++) if(indeg[i] == 0) Q.push_back(i);

    while(!Q.empty())
    {
        s = Q.front();
        Q.pop_front();
        cout<<s+1<<" ";
        for(j = adj[s].begin();j!=adj[s].end();j++)
        {
            indeg[*j]--;
            if(indeg[*j] ==0)
                Q.push_back(*j);
        }
    }
    cout<<"\n";
}

int main()
{
    Graph g(8);
    /*g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(4, 8);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(6, 9);
    g.addEdge(7, 5);
    g.addEdge(7, 6);
    g.addEdge(8, 4);
    g.addEdge(8, 9);
    g.addEdge(9, 6);
    g.addEdge(9, 8);
    g.addEdge(9, 10);
    g.addEdge(10,9);*/

    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 8);


    cout<<"\nTopology sort by method 1 (using stack): \n";
    g.TopologySort();

    cout<<"\nTopology sort by method 2 (without using stack)\n";
    g.TopologySort2();
    return 0;
}

