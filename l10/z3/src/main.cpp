#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string str;
	string fname;

	printf("Enter file name: ");
	cin >> fname;
	if(fname==""){
		cout << "No file name give" << endl;
		return 0;
	}

	ifstream file(fname);
	if(!file.good()){
		cout << "File not found" << endl;
	}else{
		getline(file, str);
	}
	file.close();

	int bad = 0;
	const string verify = "0123456789+-=/*()";
	for(auto &s : str){
		for(auto &v : verify){
			if(s==v){
				bad = 0;
				break;
			}else{bad = 1;}
		}
		if(bad==1)break;
	}

	printf( bad==0 ? "Ok.\n" : "Not Ok!!!\n");
	return 0;
}
