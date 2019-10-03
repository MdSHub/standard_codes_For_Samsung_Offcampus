#include<iostream>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        string input;
        cin>>input;
        int n=input.length();
        int next_state,current_state=1,count=0;
        for(int i=0;i<n;i++)
        {
            char c=input[i];

        if(current_state==1)
        {
            if(c=='0')
                next_state=1;
            else if(c=='1')
                next_state=2;
            else
                next_state=1;
         }
        else  if(current_state==2)
        {
              if(c=='0')
                next_state=3;
            else if(c=='1')
                next_state=2;
            else
                next_state=1;
        }
        else  if(current_state==3)
        {
             if(c=='0')
                next_state=3;
            else if(c=='1')
                next_state=4;
            else
                next_state=1;

        }
        else  if(current_state==4)
        {
             if(c=='0')
                next_state=3;
            else if(c=='1')
                next_state=2;
            else
                next_state=1;
        }

        current_state=next_state;
        if(current_state==4)
            count++;

        }
        cout<<count<<endl;
    }


    return 0;
}
