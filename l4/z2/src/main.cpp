#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(0));

	vector<int> s2;
	int s1[30];

	printf("Original Array: \n");

	for(int i = 0; i < 30; i++){
		s1[i] = rand() % 50 - 25;
		printf("%4i;", s1[i]);
		if(i % 10 == 9) printf("\n");
		if(s1[i]>0 && i%2==1) s2.push_back(s1[i]);
	}

	printf("Modded Array: \n");

	for(int i = 0; i < s2.size(); i++){printf("%4i;", s2[i]); if(i % 10 == 9) printf("\n");}

	printf("\n");
	return 0;
}

