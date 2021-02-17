#include <stdio.h>
#include <cmath>

using namespace std;

double ln(double x);
double lg(double x);

int main(){
	double Y = 0;
	int x = 0;
	int b = 0;

	printf("Enter b: ");
	scanf("%i", &b);
	printf("Enter x: ");
	scanf("%i", &x);

	if(b*x > 1){
		Y = b*x - ln(abs(x));
	}else if(b*x < 1){
		Y = b*x + lg(abs(x));
	}else Y = 1;

	printf("%.2f\n",Y);

	return 0;
}

double ln(double x){return log(x)/log(M_E);}
double lg(double x){return log(x)/log(10);}
