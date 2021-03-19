#ifndef TYPE_H
#define TYPE_H

#include <string>

using std::string;

typedef struct{
	string city;
	string street;
	string house;
	string apartament;
}Addr;

typedef struct{
	string surname;
	string name;
	int age;
	string sex;
	Addr addres;
}worker;
#endif
