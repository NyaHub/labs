#include <stdio.h>
#include <math.h>

using namespace std;

int main(){

	float nn[33];
	float s = 0;

	for(int i = 0; i < 33; i++){
		nn[i] = rand()/rand();
		if(i >= 32-10)
			s += nn[i];
		printf("%2.1f ", nn[i]);
	}
	s /= 10;

	printf("\n");

	for(int i = 0; i < 10; i++)
		nn[i] = s;

	for(int i = 0; i < 33; i++)
		printf("%2.1f ", nn[i]);

	printf("\n");

	return 0;
}
