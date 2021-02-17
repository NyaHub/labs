#include <stdio.h>
#include <math.h>

float S(int a);
float L(int a);

int main(){
	const float a = 4.35;
	printf("S = %1.2f;\nL = %1.2f.\n", S(a), L(a));
	return 0;
}

float S(int a){
	return (sqrt(3)*pow(a,2))/4;
}

float L(int a){
	return (sqrt(3)*a)/2;
}
