#ifndef MAGIC_H
#define MAGIC_H

#include <string>
#include <vector>
#include <iostream>
#include "type.h"
#include "my_string.h"
#include "file.h"

using std::string, std::cout, std::cin, std::vector, std::endl;

void printPerson(worker p);
void printAll(vector<worker> w);
vector<worker> __exp(vector<worker> w, string expr);
vector<worker> __merge(vector<worker> res, vector<worker> add);
vector<worker> __multi_exp(vector<worker> w, vector<string> expr);
vector<worker> exp(vector<worker> w, vector<string> expr);

#endif
