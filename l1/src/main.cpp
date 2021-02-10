#include <stdio.h>
#include <math.h>

float f(float x, int p);

int main(){
	float x = 0;
	int p = 0;
	printf("Hello!\n");
	printf("Enter x: ");
	scanf("%f", &x);
	printf("Enter p: ");
	scanf("%d", &p);
	printf("%1.3f\n", f(x,p));
	return 0;
}

float f(float x, int p){
	return sin(pow(x,4)-.4*p)+(cos(x)+1)/(sqrt(abs(tan(p+1))));
}
