#include<iostream>
using namespace std;


struct queueEntry{
int  x;
int y;
int cost;


};

class queue{
public:
    int start;
    int end;
    int size;
    int array[2000][3];
    queue()
    {
        start=0;
        end=0;
        size=0;
        for(int i=0;i<2000;i++)
        {
            array[i][0]=0;
            array[i][1]=0;
            array[i][2]=0;

        }

    }

    void push(queueEntry q)
    {
        array[end][0]=q.x;
        array[end][1]=q.y;
        array[end][2]=q.cost;
        end++;
        size++;

    }
  queueEntry pop()
  {
      queueEntry q;
      q.x=array[start][0];
      q.y=array[start][1];
      q.cost=array[start][2];
      size--;
      start++;
      return q;

  }

  bool isEmpty()
  {
     if(size==0)
            return true;
     else
        return false;

  }

};

int num_rows,num_cols,num_rare;
int matrix[20][20],visited[20][20],dist[5],rare_loc[5][2],costs[400];

void initialize()
{
    num_rows=0;
    num_cols=0;
    num_rare=0;

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {

            matrix[i][j]=0;
            visited[i][j]=0;
        }

    }
    for(int i=0;i<5;i++)
    {
        rare_loc[i][0]=0;
        rare_loc[1][1]=0;
    }


    for(int i=0;i<400;i++)
    {
        costs[i]=-1;
    }


}


void reset()
{
    for(int i=0;i<20;i++)
      for(int j=0;j<20;j++)
            visited[i][j]=0;
}

int DFS(int x,int y)
{
    int max_cost=0;
    queue q;

    q.push({x,y,0});
    visited[x][y]=1;

    while(q.isEmpty()==false)
    {

        queueEntry v=q.pop();
        int x=v.x;
        int y=v.y;
        int cost=v.cost;

        if(matrix[x][y]==2){
            if(cost>max_cost)
                max_cost=cost;

        }
        if(x-1>=0 && (visited[x-1][y]==0 && matrix[x-1][y]!=0))
        {
          q.push({x-1,y,cost+1});
          visited[x-1][y]=1;
        }
        if(y-1>=0&& (visited[x][y-1]==0 && matrix[x][y-1]!=0))
        {
            q.push({x,y-1,cost+1});
          visited[x][y-1]=1;
        }
        if(x+1<num_rows&& (visited[x+1][y]==0 && matrix[x+1][y]!=0))
        {
            q.push({x+1,y,cost+1});
          visited[x+1][y]=1;
        }
        if(y+1<num_cols&& (visited[x][y+1]==0 && matrix[x][y+1]!=0))
        {
            q.push({x,y+1,cost+1});
          visited[x][y+1]=1;
        }


    }
    return max_cost;

}




int driver()
{
    for(int i=0;i<num_rare;i++)
    {
        int x=rare_loc[i][0];
        int y=rare_loc[i][1];
        matrix[x][y]=2;

    }

    for(int i=0;i<num_rows;i++)
    {
        for(int j=0;j<num_cols;j++)
        {
            if(matrix[i][j]!=0){
                reset();
                costs[20*i+j]=DFS(i,j);
            }
        }
    }

    int min_cost=5000;
    for(int i=0;i<400;i++)
    {
        if(costs[i]!=-1 && costs[i]<min_cost)
            min_cost=costs[i];

    }
    if(min_cost==5000)
        return 0;
    else
        return min_cost;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n_r,n_c,n_rare;
        num_rows=n_r;
        num_cols=n_c;
        num_rare=n_rare;
        cin>>n_r>>n_c>>n_rare;
        for(int i=0;i<n_r;i++)
            for(int j=0;j<n_c;j++)
                cin>>matrix[i][j];


        for(int i=0;i<n_rare;i++)
            cin>>rare_loc[i][0]>>rare_loc[i][1];


        int result=driver();

        for(int i=0;i<n_r;i++)
           {for(int j=0;j<n_c;j++)
                cout<<costs[20*i+j];
                cout<<endl;
           }

        cout<<endl;
        cout<<result;

    }



    return 0;
}



