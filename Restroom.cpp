#include<iostream>
using namespace std;

void printStalls(bool *A,int N)
{

for(int i=0;i<N;i++)
{
  if(A[i])
   cout<<"X ";
   else
   cout<<"_ ";

}
cout<<endl;
}


int nextStalls(bool *A,int N)
{
  int LIndex=-1;
  int LRun=0;
  int CIndex=-1;
  int CRun=0;
    bool inRun=false;

    for(int i=0;i<N;i++)
    {
       if(!inRun && !A[i])
       {  inRun=true;
          CIndex=i;
          CRun=1;
       }
       else if(inRun && !A[i])
       {
         CRun++;
       }
       else if(inRun && A[i])
       {
         inRun=false;
         if(CRun>=LRun)
         {
           LRun=CRun;
           LIndex=CIndex;

         }


       }

    }

    if(inRun)
    {
       if(CRun>=LRun)
       {
         LRun=CRun;
         LIndex=CIndex;
       }


    }

    return ((LRun-1)/2)+LIndex;


}


int main()
{
int N;
cin>>N;
bool *stalls=new bool[N];
for(int i=0;i<N;i++)
{
  stalls[nextStalls(stalls,N)]=true;
  printStalls(stalls,N);


}

return 0;

}
