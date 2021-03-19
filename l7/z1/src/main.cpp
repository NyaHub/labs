#include <iostream>
#include <string>
#include <vector>
#include "type.h"
#include "my_string.h"
#include "file.h"

using std::string, std::cout, std::cin, std::vector, std::endl;

int main(int argc, char *argv[])
{
	string path;
	if (argc > 1)
	{
		cout << "ok" << endl;
		if (argv[1] == "--path" | argv[1] == "-p")
		{
			path = argv[2];
		}
	}
	else
	{
		path = "res/worker.json";
	}

	cout << argc << path << endl;

	CSVParser *csv = new CSVParser("res/worker.json");
	vector<worker> w = csv->parseFile();
	cout << w[0].addres.city << " hui" << endl;
	// cout << w.data()->name << endl;
	//	for(auto s : w){
	//		if()
	//		cout << typeid(s).name() << endl;
	//	}
	return 0;
}
