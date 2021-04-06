#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	ifstream infile("in.file");
	if(!infile.good()){
		cout<< "in file not found" << endl;
		return 0;
	}

	ofstream outfile("out.file");

	string line;
	while(getline(infile, line)){
		outfile << "'" << line << "'" << endl;
	}
	infile.close();
	outfile.close();

	return 0;
}
