#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(0));
	float L[9][4];
	float s = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 4; j++){
			L[i][j] = (rand() % 200 - 100.0) / 15.0;
			if(L[i][j]>0) s = s == 0 ? L[i][j] : (s+L[i][j])/2;
			printf("%6.1f;", L[i][j]);
		}
		printf("\n");
	}

	printf("\n%.1f\n", s);

	return 0;
}
