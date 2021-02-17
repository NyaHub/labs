#include <iostream>
#include <math.h>

using namespace std;

float f(float x, int p);

int main(){
	float x = 0;
	int p = 0;
	cout << "Hello!" << endl;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter p: ";
	cin >> p;
	cout << f(x,p) << endl;
	return 0;
}

float f(float x, int p){
	return sin(pow(x,4)-.4*p)+(cos(x)+1)/(sqrt(abs(tan(p+1))));
}
