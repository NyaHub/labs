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

struct worker{
	string surname;
	string name;
	int age;
	string sex;
	Addr addres;

	bool operator==(const worker& w)const{
		if (w.surname != this->surname) return false;
		if (w.name != this->name) return false;
		if (w.age != this->age) return false;
		if (w.sex != this->sex) return false;
		if (w.addres.city != this->addres.city) return false;
		if (w.addres.street != this->addres.street) return false;
		if (w.addres.house != this->addres.house) return false;
		if (w.addres.apartament != this->addres.apartament) return false;
		return true;
	}
	bool operator>(const worker& w)const{
		if (w.surname > this->surname) return false;
		if (w.name > this->name) return false;
		if (w.age > this->age) return false;
		if (w.sex > this->sex) return false;
		if (w.addres.city > this->addres.city) return false;
		if (w.addres.street > this->addres.street) return false;
		if (w.addres.house > this->addres.house) return false;
		if (w.addres.apartament > this->addres.apartament) return false;
		return true;
	}
	bool operator<(const worker& w)const{
		if (w.surname < this->surname) return false;
		if (w.name < this->name) return false;
		if (w.age < this->age) return false;
		if (w.sex < this->sex) return false;
		if (w.addres.city < this->addres.city) return false;
		if (w.addres.street < this->addres.street) return false;
		if (w.addres.house < this->addres.house) return false;
		if (w.addres.apartament < this->addres.apartament) return false;
		return true;
	}
	bool operator!=(const worker& w)const{
		if (w.surname == this->surname) return false;
		if (w.name == this->name) return false;
		if (w.age == this->age) return false;
		if (w.sex == this->sex) return false;
		if (w.addres.city == this->addres.city) return false;
		if (w.addres.street == this->addres.street) return false;
		if (w.addres.house == this->addres.house) return false;
		if (w.addres.apartament == this->addres.apartament) return false;
		return true;
	}
};
// typedef worker;
#endif
