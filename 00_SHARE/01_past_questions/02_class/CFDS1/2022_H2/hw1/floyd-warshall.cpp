#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

const int NIL = -1;
const int INF = INT8_MAX;

#define N 5
vector<vector<int>> d(N, vector<int>(N)); //to store weight between (i,j)
vector<vector<int>> p(N, vector<int>(N)); //to store predecessor of j

void initD(vector<vector<int>> const &w) {
    for(int v = 0; v < N; v++){
        for (int u = 0; u < N; u++){
            d[v][u] = w[v][u];
            p[v][u] = NIL;
            
            if((v!=u) && w[v][u] != INF)
            p[v][u] = v + 1;
            
        }
    }
}

// 문제 3번. floydWarshall()의 구현으로 알맞은 코드를 고르시오.
void floydWarshall(vector<vector<int> > const &w, const int n){
for(int z=0; z<n; z++){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(d[i][z] != INF && d[z][j] != INF && d[i][z] + d[z][j] < d[i][j]){
				d[i][j] = d[i][z] + d[z][j];
				p[i][j] = p[z][j];
				}
			}
		}
	}
}

// Main 
int main() {
    vector<vector<int>> adjMatrix = {
        {0, INF, 5, 4, INF},
        {3, 0, INF, INF, INF},
        {INF, INF, 0, 2, INF},
        {INF, 1, 1, 0, INF},
        {INF, 4, INF, 2, 0}
};
initD(adjMatrix);
floydWarshall(adjMatrix, N);

// Print matrix d
cout << "Print matrix d"<< endl;
for(int i=0; i<N; i++){
    for(int j =0; j<N; j++){
        if(d[i][j] == INF)
	        cout<< "INF" << " ";
        else
	        cout << setw(3) << d[i][j] << " ";   
		    }
		    cout << endl;
}

// Print matrix  p
cout << "\nPrint matrix p"<< endl;
for (int i=0; i<N; i++){
    for(int j=0; j<N; j++){
        if(p[i][j] == NIL)
            cout << "NIL" << " ";
        else
            cout << setw(3) << p[i][j] << " ";
        }
        cout << endl;
}    

return 0;
}