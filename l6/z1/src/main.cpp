#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(){
	string str;
	printf("Enter string: ");
	getline(cin, str);

	int h1, h2 = 0;
	int len = str.length();
	for(int i = 0; i < len; i++){
		if(str[i]=='k')
		if(i < len/2) h1++;
		else h2++;
	}
	printf(h1>h2 ? "in first\n" : (h1<h2 ? "in second\n" : "is equal\n"));
	return 0;
}
