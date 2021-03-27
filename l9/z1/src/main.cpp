#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef struct{
int x1;
int x2;
}nums;

nums f1(int a, int b, int c);
int f2(nums x, nums y);

int main(){

	int a, b, c;
	cout << "Enter a, b, c:"; cin >> a >> b >> c;
	nums x = f1(a,b,c);

	cout << "Enter a, b, c:"; cin >> a >> b >> c;
	nums y = f1(a,b,c);

	int z = f2(x,y);

	cout << "z = " << z << endl;

	return 0;
}

nums f1(int a, int b, int c){
	nums out;
	if(a==0){
		out.x1 = -c/b;
		out.x2 = 0;
		return out;
	}
	if(b==0){
		out.x1 = sqrt(-c/a);
		out.x2 = -out.x1;
		return out;
	}
	if(c==0){
		out.x1 = 0;
		out.x2 = -b/a;
		return out;
	}
	int d = sqrt(pow(b,2)-4*a*c);
	out.x1 = (-b-d)/(2*a);
	out.x2 = (-b+d)/(2*a);
	return out;

}

int f2(nums x, nums y){return abs(x.x1 - y.x1)/(x.x2 * y.x2);}

