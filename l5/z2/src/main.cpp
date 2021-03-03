#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(0));
	int K[5][5];
	int s = 0;
	vector<int> temp;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			K[j][i] = (rand() % 200 - 100);
			if(abs(K[j][i])%2==1) s += K[j][i];
		}
		temp.push_back(s);
		s = 0;
	}
	printf("Matrix:\n");
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++) printf("%6i;", K[i][j]);
		printf("\n");
	}
	printf("Additional row:\n");
	for(int i = 0; i < temp.size(); i++) printf("%6i;", temp[i]);
	printf("\n");
	return 0;
}
