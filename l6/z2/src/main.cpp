#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(){
	string str;

	printf("Enter string: ");
	getline(cin, str);

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
