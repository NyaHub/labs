#include <iostream>
#include <math.h>

using namespace std;

float S(int a);
float L(int a);

int main(){
	const float a = 4.35;
	cout << "S = "<< S(a) << endl << "L = " << L(a) << endl;
	return 0;
}

float S(int a){
	return (sqrt(3)*pow(a,2))/4;
}

float L(int a){
	return (sqrt(3)*a)/2;
}
