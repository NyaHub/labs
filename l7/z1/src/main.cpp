#include <iostream>
#include <string>
#include <vector>

// magic functions &*$#*\(*0*)/*#$*&
#include "type.h"
#include "my_string.h"
#include "file.h"
#include "magic.h"
//end my magic

using std::string, std::cout, std::cin, std::vector, std::endl;

void add(vector<worker> *w, Parser *p);
void printHelp();
void del(string uIn, vector<worker> *w, Parser *p);
void select(string uIn, vector<worker> *w);
vector<worker> exp(vector<worker> w, vector<string> expr);

void zadanie(vector<worker> *w); // zadanie

//MORE magic &*$#*\(*0*)/*#$*&

int main(int argc, char *argv[])
{
	string path;

	if (argc > 1)
		path = argv[1];
	else
		path = "res/worker.json";

	Parser *p = new Parser(path);
	vector<worker> w = p->parseFile();

	zadanie(&w);

	const string com[] = {"/q", "/h", "/s", "/a", "/d"};
	string uIn;
	while (uIn != com[0])
	{
		if (uIn[0] == '/')
		{
			switch (uIn[1])
			{
			case 'h':
				printHelp();
				break;
			case 's':
				select(uIn, &w);
				break;
			case 'a':
				add(&w, p);
				break;
			case 'd':
				del(uIn, &w, p);
				break;
			case 'z':
				zadanie(&w);
			default:
				printHelp();
			}
		}
		else
			printHelp();
		cout << ">>";
		getline(cin, uIn);
	}
	return 0;
}

void zadanie(vector<worker> *w){
	// Тут происходит основная магия.
	// Но для того чтобы посмотреть, что под копотом этих функций придется
	// сходить в мой github: https://guthub.com/NyaHub/labs.git
	// Ах да, часть магии происходит выше, но это скорее подготовка к этому.
	// Кстати, я забыл про должность человеков, но я думаю масштаб проекта
	// перекроет этот маленький недостаток. :)
	printf("\n\n-----------Vse devushki moloje 35 godikov: \n");
	string query = "/s sex=woman and age<35";
	select(query, w);
	printf("\n\n-----------Samii startii mujik: \n");
	query = "/s sex=man and age=max";
	select(query, w);
}

void select(string uIn, vector<worker> *w)
{
	vector<string> args = split(" ", uIn);

	if (args.size() < 2)
	{
		printf("ERROR: no arguments.\n");
		return;
	}
	if (args[1] == "*")
	{
		printAll(*w);
		return;
	}

	vector<worker> tmp = exp(*w, args);

	printAll(tmp);
}

void del(string uIn, vector<worker> *w, Parser *p)
{
	vector<string> args = split(" ", uIn);

	if (args.size() < 2)
	{
		printf("ERROR: no arguments.\n");
		return;
	}

	vector<worker> tmp = exp(*w, args);

	int it = 0;
	vector<worker> v = *w;
	for (auto i : v)
	{
		it++;
		for (auto j : tmp)
		{
			if (i == j)
				w->erase(w->begin() + it - 1);
		}
	}
	p->reset(w);
}
void printHelp()
{
	printf("\n/q       - quit\n");
	printf("/h       - help (this page)\n");
	printf("/s [exp] - select by exp\n");
	printf("/a       - add interact\n");
	printf("/d [exp] - delete by exp\n");
	printf("/z       - zadanie (autorun)\n\n");
}
void add(vector<worker> *w, Parser *p)
{
	worker tmp;
	cout << "Enter name: ";
	cin >> tmp.name;
	cout << "Enter surname: ";
	cin >> tmp.surname;
	cout << "Enter age: ";
	cin >> tmp.age;
	cout << "Enter sex: ";
	cin >> tmp.sex;
	cout << "Enter city: ";
	cin >> tmp.addres.city;
	cout << "Enter street: ";
	cin >> tmp.addres.street;
	cout << "Enter house: ";
	cin >> tmp.addres.house;
	w->push_back(tmp);
	p->write(tmp);
}
