   int n= A.size();
    
    for(int i=0;i<n;i++){
        while(A[i]>=1 && A[i]<=n && A[i]!= i+1){

            
            int v = A[i];
            if(A[i] == A[v-1])
              break;
            swap(A[i],A[v-1]);


        }
    }

    for(int i=0;i<n;i++){
        if(A[i] != i+1){
            return i+1;
        }
    }
      return n+1;   
    }
