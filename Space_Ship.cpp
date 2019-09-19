/*
There is one spaceship. X and Y coordinate of source of spaceship and destination spaceship is given.
There are N number of wormholes each wormhole has 5 values.
First 2 values are starting co-ordinate of wormhole and after that value no. 3 and 4 represents ending co-ordinate of wormhole
and last 5th value is represents cost to pass through this wormhole.
Now these wormholes are bi-direction.
Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
The main problem here is to find minimum distance to reach spaceship from source to destination co-ordinate using any number of warm-hole.
It is ok if you wont use any wormhole.
Hint:
You can make graph which contain edge between all points and put cost of that edge.
Now apply djikstra algorithm to find minimum distance between source to destination co-ordinate of spaceship.
Here the main catch is that the cost to pass through wormhole can be zero so you have to take care while making graph matrix.
*/


#include<iostream>
using namespace std;
#define i_max 2147483647
int nw,sx,sy,dx,dy;//Source and destination co-ordinates
int dist[1001][1001];
bool set[1001][1001];
class Wormhole{
	public:
		int x1,y1,x2,y2,cost;
		
		void get(){
			cin >> x1 >> y1 >> x2 >> y2 >> cost;
		}
};
Wormhole A[10];
int row_mov[] = {1,-1,0,0};
int col_mov[] = {0,0,1,-1}; 


void initializeArrays(int m,int n){
	//Filling array with 1s
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dist[i][j] = i_max;
			set[i][j] = false;
		}
	}
}

void setMinRowCol(int &row,int &col){
	int min_dist=i_max,min_i=-1,min_j=-1;
	for(int i=1;i<=dx;i++){
		for(int j=1;j<=dy;j++){
			if(!set[i][j] && dist[i][j]<min_dist){
				min_dist = dist[i][j];
				min_i = i;
				min_j = j;
			}
		}
	}
	row = min_i;
	col = min_j;
}

int wormentry(int i,int j)
{
    for(int k=0;k<nw;k++)
    {
        if(A[k].x1==i && A[k].y1==j)
            return k;
    }
    return -1;
}

int wormexit(int i,int j)
{
    for(int k=0;k<nw;k++)
    {
        if(A[k].x2==i && A[k].y2==j)
            return k;
    }
    return -1;
}

bool isValid(int i,int j){
	if(i<1 || j<1 || i>dx || j>dy){
		return false;
	}
	return true;
}

int findMinCost(){
	initializeArrays(dx+1,dy+1);
	//Run dijkstra
	dist[sx][sy] = 0;//Distance from source to source is 0
	//set[sx][sy] = true;//We have reached source
	
	for(int i=1;i<=dx*dy;i++){
		int row=-1,col=-1;
		setMinRowCol(row,col);//Find min row,col that are unset and proceed with min_dist path
		
		if(row == -1 && col == -1){//If not found then break
			break;
		}
		if(row == dx && col == dy){//If we've reached destination, return the cost
			return dist[row][col];
		}
		
		set[row][col] = true;//Set the current row,col
		
		for(int j=0;j<4;j++)//Move in all 4 directions
        {
            int x = row + row_mov[j];
            int y = col + col_mov[j];

            if(isValid(x,y) && !set[x][y] && dist[x][y]>dist[row][col]+1)
                dist[x][y] = dist[row][col] + 1;
        }
        
        int w_entry = wormentry(row,col);//If worm entry is at row,col ,i.e., row = x1 & col = y1 then exit is at x2,y2
        if(w_entry!=-1)
        {
            int x = A[w_entry].x2;
            int y = A[w_entry].y2;

            if(!set[x][y] && dist[x][y]>dist[row][col]+A[w_entry].cost) //If cost of wormhole is minimum go through the wormhole
                dist[x][y] = dist[row][col]+A[w_entry].cost;
        }
        int w_exit = wormexit(row,col);//If worm exit is at row,col ,i.e., row = x2 & col = y2 then entry is at x1,y1
        if(w_exit!=-1)
        {
            int x = A[w_exit].x1;
            int y = A[w_exit].y1;

            if(!set[x][y] && dist[x][y]>dist[row][col]+A[w_exit].cost) //If cost of wormhole is minimum go through the wormhole
                dist[x][y] = dist[row][col]+A[w_exit].cost;
        }
	}
	return -1;
}

int main(){
	cin >> sx >> sy >> dx >> dy;//Scanning source and destination
	
	cin >> nw;//No of wormholes
	
	//Scanning wormholes info
	for(int i=0;i<nw;i++){
		A[i].get();
	}
	
	cout << findMinCost();
	return 0;
}
