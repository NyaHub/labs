#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

float foo(int * arr, size_t len);
void print_arr(int * arr, size_t len);

int main(){
	srand(time(0));

	size_t mmmlen, wwwlen;

	string fname;
	cout << "Enter file name: "; cin >> fname;

	if(fname==""){
		cout << "No given file name" << endl;
		return 0;
	}

	ofstream file(fname, ios::in);
	if(!file.isopen()){
		cout << "Enter len of mmm array: "; cin >> mmmlen;
		cout << "Enter len of www array: "; cin >> wwwlen;

		int mmm[mmmlen];
		int www[wwwlen];
		for(int i=0; i<max(mmmlen, wwwlen); i++){
			if(i<wwwlen) www[i] = rand()%100+50;
			if(i<mmmlen) mmm[i] = rand()%100+50;
		}
	}else{
		//read len
		int mmm[mmmlen];
		int www[wwwlen];
		for(int i=0; i<max(mmmlen, wwwlen); i++){
			if(i<wwwlen) www[i] = rand()%100+50;
			if(i<mmmlen) mmm[i] = rand()%100+50;
		}
	}
	cout << "mmm:" << endl;
	print_arr(mmm, mmmlen);
	cout << "www:" << endl;
	print_arr(www, wwwlen);

	cout << "AVG mmm: " << foo(mmm, mmmlen) << endl;
	cout << "AVG www: " << foo(www, wwwlen) << endl;
}

float foo(int * arr, size_t len){
	double out;
	for(int i = 0; i<len; i++){
		out += pow(arr[i], 2);
	}
	return sqrt(out);
}

void print_arr(int * arr, size_t len){
	for(int i = 0; i < len; i++){
		if(i%10 == 9) printf("%6i\n", arr[i]);
		else printf("%6i", arr[i]);
	}
	cout << endl;
}
