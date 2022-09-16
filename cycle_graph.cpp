/*
Find a cycle, if exists, in a directed graph.
If there is none, print 0.
If there is one, print the path starting from the first node of the cycle to the last.
If there are more than one, print any path.
1<=N<=100
Sample Input:
5
6 12    //Single loop
0 1
0 2
0 5
1 3
1 5
2 1
2 4
3 0
4 3
5 0
5 3
5 4
6 12    //Single loop
0 1
0 2
0 5
1 3
1 5
2 0
2 4
3 0
4 3
5 0
5 3
5 4
6 13       //Self Loop
0 1
0 2
0 5
1 1
1 3
1 5
2 1
2 4
3 0
4 3
5 0
5 3
5 4
6 15        // No loop
0 1
0 2
0 3
0 4
0 5
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
6 6             //Single Loop not from origin
0 1
1 2
2 5
5 1
2 3
3 4
6 5             //Disconnected Components
1 2
2 5
5 1
2 3
3 4
Output:
0->1->3->0
0->1->3->0
1->1
-1
*/


#include<stdio.h>

int V[100][100];
int visited[100];
int N,E;
int k,l;
int path[100];


void input(){
 scanf("%d",&N);
 scanf("%d",&E);
 for(int i=0;i<E;i++){
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    V[x][y] = 1;
 }


}


void reset(){
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++)
            V[i][j]=0;
            visited[i]=0;
            path[i]=-1;
    }


    k=-2;
    l=-2;

}


  int recur(int node, int counter){

      path[counter]= node;

      for(int y=0;y<N;y++){
        if(V[node][y] == 1){
            if(visited[y]==1){
                k=y;
                l=node;
                return -1;
            }
            visited[y] = 1;
            int i = recur(y,counter+1);
            if(i==-1){
                return -1;
            }
            visited[y]= 0;
        }
      }




  }


  void output(){
     printf("\n");
     if(k==-2){
      printf("-1\n");return;//No cycle

     }
     if(k==-1){
        printf("%d",path[0]);
        printf("\n");
         return;
     }
     int start_idx = 0;
     for(int i=0;i<100;i++){
        if(path[i]==k){
            start_idx =i;
        }
     }

     for(int i=start_idx;i<100;i++){
        if(path[i]==l){
            printf("%d",path[i]);
            printf("->");
            break;
        }
         printf("%d",path[i]);
        printf("->");
     }

     printf("%d",path[start_idx]);
     printf("\n");

   }



  void driver(){
        for(int x=0;x<N;x++){
                visited[x] = 1;
                path[0]=x;

                for(int y=0;y<N;y++){
                    if(V[x][y]==1){
                            if(visited[y]==1){
                                if(x==y){
                                    k=-1;
                                    return;
                                }
                            }
                            visited[y] = 1;
                            int ret = recur(y,1);
                            if(ret==-1){
                              return;
                             }
                            visited[y]=0;

                }

        }



     }
  }


  int main(){

    int test;
    scanf("%d",&test);

    while(test--){
        reset();
        input();
        driver();
        output();

    }


     return 0;


  }
