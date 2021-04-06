#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <iterator>

using namespace std;

float foo(int * arr, size_t len);
void print_arr(int * arr, size_t len);

int main(){
	srand(time(0));

	size_t mmmlen, wwwlen;

	int * mmm;
	int * www;

	string fname;
	cout << "Enter file name: "; cin >> fname;

	const int intSize = sizeof(int);

	if(fname==""){
		cout << "No given file name" << endl;
		return 0;
	}

	ifstream file(fname);
	if(!file.good()){
		file.close();
		ofstream file(fname);

		cout << "Enter len of mmm array: "; cin >> mmmlen;
		cout << "Enter len of www array: "; cin >> wwwlen;

		file << mmmlen << endl << wwwlen << endl;

		mmm = (int *)calloc(mmmlen, intSize);
		www = (int *)calloc(wwwlen, intSize);
		cout<<"for" << endl;
		for(int i=0; i<mmmlen + wwwlen; i++){
			int n = rand()%100+50;
			file << n << endl;
			if(i<mmmlen) mmm[i] = n;
			if(i>=mmmlen) www[i-mmmlen] = n;
		}
	}else{
		string tmp;

		getline(file,tmp);mmmlen = stoi(tmp);
		getline(file,tmp);wwwlen = stoi(tmp);

		mmm = (int *)calloc(mmmlen, intSize);
		www = (int *)calloc(wwwlen, intSize);
		for(int i=0; i<mmmlen + wwwlen; i++){
			getline(file,tmp);
			if(i<mmmlen) mmm[i] = stoi(tmp);
			if(i>=mmmlen) www[i-mmmlen] = stoi(tmp);
		}
	}
	file.close();
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
