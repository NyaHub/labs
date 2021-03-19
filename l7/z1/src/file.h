#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "type.h"
#include "../include/json.hpp"

using namespace std;
using json = nlohmann::json;

class CSVParser
{

private:
    string path;

public:
    CSVParser(string path)
    {
        this->path = path;
    }

    vector<worker> parseFile()
    {
        ifstream pipe(this->path);
        vector<worker> out;
        string line;
        while (getline(pipe, line))
        {
            worker tmp;
            auto j = json::parse(line);
            tmp.surname = j["surname"];
            tmp.name = j["name"];
            tmp.age = j["age"];
            tmp.sex = j["sex"];
            tmp.addres.city = j["addres"]["city"];
            tmp.addres.street = j["addres"]["street"];
            tmp.addres.house = j["addres"]["house"];
            tmp.addres.apartament = j["addres"]["apartament"];
            out.push_back(tmp);
            cout << line << endl;
        }
        pipe.close();
        return out;
    }

    bool write(worker el)
    {
        fstream pipe(this->path);
        json j;
        j["surname"] = el.surname;
        j["name"] = el.name;
        j["age"] = el.age;
        j["sex"] = el.sex;
        j["addres"]["city"] = el.addres.city;
        j["addres"]["street"] = el.addres.street;
        j["addres"]["house"] = el.addres.house;
        j["addres"]["apartament"] = el.addres.apartament;

        string out = j.dump();
        if (pipe.is_open())
        {
            pipe << out << endl;
            pipe.close();
        }
        else
            return false;

        return true;
    }
};

#endif
