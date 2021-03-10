#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define N 10
#define M 10

using namespace std;

int main(){
	srand(time(0));
//	srand(1);

	vector<int> tmpOt, tmpNOt;
	int m[N][M];

	printf("Matrix[%3i x %3i]:\n", N, M);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			m[i][j] = rand() % 200 - 100;
			if(m[i][j]<0) tmpOt.push_back(m[i][j]);
			else tmpNOt.push_back(m[i][j]);
			printf("%6i", m[i][j]);
		}
		printf("\n");
	}

	sort(tmpOt.begin(), tmpOt.end());
	sort(tmpNOt.begin(), tmpNOt.end());

	printf("Modified matrix:\n");
	for(int i = 0; i < N * M; i++){
		m[i/M][i%M] = i < tmpOt.size() ? tmpOt[i] : tmpNOt[i - tmpOt.size() + 1];
		printf(i%M == M-1 ? "%6i\n" : "%6i", m[i/M][i%M]);
	}
	return 0;
}
