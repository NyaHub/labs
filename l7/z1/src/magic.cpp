#include "magic.h"

void printPerson(worker p)
{
	printf("------Person------\n");
	printf("%s %s\n", p.surname.c_str(), p.name.c_str());
	printf("Age: %i years\n", p.age);
	printf("Sex: %s\n", p.sex.c_str());
	printf("Addres: %s %s %s\n", p.addres.city.c_str(), p.addres.street.c_str(), p.addres.house.c_str());
	printf("-------end--------\n");
}
void printAll(vector<worker> w)
{
	for (auto i : w)
	{
		printPerson(i);
	}
}

vector<worker> __exp(vector<worker> w, string expr)
{
	vector<string> tmp;
	vector<worker> out;
	int pos;
	if (pos = expr.find(">"); pos != string::npos)
	{
		tmp = split(">", expr);
		pos = 0;
	}
	else if (pos = expr.find("<"); pos != string::npos)
	{
		tmp = split("<", expr);
		pos = 1;
	}
	else if (pos = expr.find("="); pos != string::npos)
	{
		tmp = split("=", expr);
		pos = 2;
	}
	else
	{
		printf("ERROR: error in syntax: %s\n", expr.c_str());
		return out;
	}
	if(tmp[0]!="age" && (tmp[1]=="max"||tmp[1]=="min")){
		printf("ERROR: min/max only with int: %s\n", expr.c_str());
		return out;
	}


	bool m_flag = false;
	worker m;
	if (tmp[1]=="max"){
		tmp[1]=to_string(0);
		pos = 0;
		m_flag = true;
	}else{if (tmp[1]=="min"){
			tmp[1]=to_string(9999);
			pos = 1;
			m_flag = true;
	}}

	int it = 0;
	for (auto i : w)
	{
		it++;
		if (tmp[0] == "name")
		{
			if (pos == 0)
			{
				if (i.name > tmp[1])
				{
					out.push_back(i);
				}
			}
			else
			{
				if (pos == 1)
				{
					if (i.name < tmp[1])
					{
						out.push_back(i);
					}
				}
				else
				{
					if (pos == 2)
					{
						if (i.name == tmp[1])
						{
							out.push_back(i);
						}
					}
				}
			}
		}
		else if (tmp[0] == "surname")
		{
			if (pos == 0)
			{
				if (i.surname > tmp[1])
				{
					out.push_back(i);
				}
			}
			else
			{
				if (pos == 1)
				{
					if (i.surname < tmp[1])
					{
						out.push_back(i);
					}
				}
				else
				{
					if (pos == 2)
					{
						if (i.surname == tmp[1])
						{
							out.push_back(i);
						}
					}
				}
			}
		}
		else if (tmp[0] == "age")
		{
			
			if (pos == 0)
			{
				if (i.age > std::stoi(tmp[1]))
				{
					if(m_flag){tmp[1]=to_string(i.age);m=i;}
					else{out.push_back(i);}
				}
			}
			else
			{
				if (pos == 1)
				{
					if (i.age < std::stoi(tmp[1]))
					{
						if(m_flag){tmp[1]=to_string(i.age);m=i;}
						else{out.push_back(i);}
					}
				}
				else
				{
					if (pos == 2)
					{
						if (i.age == std::stoi(tmp[1]))
						{
							out.push_back(i);
						}
					}
				}
			}
		}
		else if (tmp[0] == "sex")
		{
			if (pos == 0)
			{
				if (i.sex > tmp[1])
				{
					out.push_back(i);
				}
			}
			else
			{
				if (pos == 1)
				{
					if (i.sex < tmp[1])
					{
						out.push_back(i);
					}
				}
				else
				{
					if (pos == 2)
					{
						if (i.sex == tmp[1])
						{
							out.push_back(i);
						}
					}
				}
			}
		}
		else if (tmp[0] == "addres.city")
		{
			if (pos == 0)
			{
				if (i.addres.city > tmp[1])
				{
					out.push_back(i);
				}
			}
			else
			{
				if (pos == 1)
				{
					if (i.addres.city < tmp[1])
					{
						out.push_back(i);
					}
				}
				else
				{
					if (pos == 2)
					{
						if (i.addres.city == tmp[1])
						{
							out.push_back(i);
						}
					}
				}
			}
		}
		else if (tmp[0] == "addres.street")
		{
			if (pos == 0)
			{
				if (i.addres.street > tmp[1])
				{
					out.push_back(i);
				}
			}
			else
			{
				if (pos == 1)
				{
					if (i.addres.street < tmp[1])
					{
						out.push_back(i);
					}
				}
				else
				{
					if (pos == 2)
					{
						if (i.addres.street == tmp[1])
						{
							out.push_back(i);
						}
					}
				}
			}
		}
		else if (tmp[0] == "addres.house")
		{
			if (pos == 0)
			{
				if (i.addres.house > tmp[1])
				{
					out.push_back(i);
				}
			}
			else
			{
				if (pos == 1)
				{
					if (i.addres.house < tmp[1])
					{
						out.push_back(i);
					}
				}

				else
				{
					if (pos == 2)
					{
						if (i.addres.house == tmp[1])
						{
							out.push_back(i);
						}
					}
				}
			}
		}
	}
	if(m_flag){
		out.clear();
		out.push_back(m);
	}
	return out;
}

vector<worker> __merge(vector<worker> res, vector<worker> add){
	for(auto i : add){
		bool ok = false;
		for(auto j : res){
			if(i==j){
				ok = true;
			}
		}
		if(!ok){res.push_back(i);}
	}
	return res;
}

vector<worker> __multi_exp(vector<worker> w, vector<string> expr)
{
	vector<worker> out;
	for (int i = 1; i < expr.size(); i++)
	{
		if (expr[i] == "and" | expr[i] == "or")
			continue;
		vector<worker> tmp;
		if (expr[i - 1] == "and")
		{
			tmp = __exp(out, expr[i]);
			out.clear();
			out = tmp;
		}
		else
		{
			if (expr[i - 1] == "or")
			{
				tmp = __exp(w, expr[i]);
				if (tmp.size() > 0)
				{
					if (out.size() > 0)
					{
						out = __merge(out, tmp);
					}
					else
					{
						out = tmp;
					}
				}
			}
			else
			{
				tmp = __exp(w, expr[i]);
				if (tmp.size() > 0)
				{
					if (out.size() > 0)
					{
						out = __merge(out, tmp);
					}
					else
					{
						out = tmp;
					}
				}
			}
		}
	}
	return out;
}

vector<worker> exp(vector<worker> w, vector<string> expr)
{
	vector<worker> tmp;

	if (expr.size() > 2)
	{
		tmp = __multi_exp(w, expr);
	}
	else
	{
		tmp = __exp(w, expr[1]);
	}

	return tmp;
}