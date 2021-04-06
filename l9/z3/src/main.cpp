#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

float foo(int * arr, size_t len);
void print_arr(int * arr, size_t len);

int main(){
	srand(time(0));

	size_t len;
	cout << "Enter array length: "; cin >> len;

	for(int i=0; i<len;i++){
		pol[i]=rand()%100-200;
		otr[i]=rand()%100-200;
	}

	cout<<"POL:"<<endl;
	print_arr(pol, len);
	cout<<"OTR:"<<endl;
	print_arr(otr, len);

	s = foo(pol, otr, len);

	cout<<"S:"<<endl;
	print_arr(s, len);

	return 0;
}

float foo(int * a1, int * a2, size_t len){
	vector<int> tmp;
	for(int i = 0; i<len; i++){
		if (a1[i]>0)tmp.push_back(a1[i]);
		if (a2[i]>0)tmp.push_back(a2[i]);
	}
	return tmp;
}

void print_arr(int * arr, size_t len){
	for(int i = 0; i < len; i++){
		if(i%10 == 9) printf("%6i\n", arr[i]);
		else printf("%6i", arr[i]);
	}
	cout << endl;
}
