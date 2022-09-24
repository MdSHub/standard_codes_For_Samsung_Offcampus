
/*
There is an island surrounded by oil mines.
You will be given n companies and m oil mines having values.
You have to distribute the mines to “n” companies in a fair manner.
Remember the companies can have oil mines adjacent to each other and not in between of each other.
After distributing them compute the difference of oil mines from the company getting highest and company getting lowest.
This number should be minimum.(then only the distribution can be termed as fair).
Input
2
2 4
6 13 10 2
2 4
6 10 13 2
Output
5
1
Assuming
0<= N <= M <= 50
*/

#include <iostream>
#include <climits>
using namespace std;

int companies, mines, ANS;

int MIN(int x, int y){
    return (x>=y) ? y : x;
}

int MAX(int x, int y){
    return (x>=y) ? x : y;
}

void calculateOilMines(int i, int *oilMines, bool *visited, int minV, int maxV, int sum,
                        int nodes, int &ANS){
    // Base Case
    if(visited[i]){
        int newMin = MIN(sum, minV);
        int newMax = MAX(sum, maxV);

        if(nodes == companies - 1){
            ANS = min(ANS, newMax - newMin);
        }
        return;
    }

    // Main Case
    visited[i] = 1;
    int j = (i + 1) % mines;   

    calculateOilMines(j, oilMines, visited, minV, maxV, sum + oilMines[i], nodes, ANS);

    int newMin = MIN(sum, minV);
    int newMax = MAX(sum, maxV);

    calculateOilMines(j, oilMines, visited, newMin, newMax, oilMines[i], nodes + 1, ANS);

    visited[i] = 0;
    return;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		cin >> companies >> mines;
		int  *oilMines = new int[mines + 1];
		bool *visited  = new bool[mines + 1];

		for(int i=0; i<mines; i++){
            cin >> oilMines[i];
            visited[i] = 0;
        }
			
        ANS = INT_MAX;    
        for(int i=0; i<mines; i++)
            calculateOilMines(i, oilMines, visited, INT_MAX, INT_MIN, 0, 0, ANS);  

		cout << ANS <<endl;		
	}
	return 0;
}
