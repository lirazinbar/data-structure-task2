#pragma once
#include <string>

class Person
{
    int id = 0;
    std::string name = "";

public:
    Person() {};
    Person(const int _id, const std::string& _name) : id(_id), name(_name) {};
    void setPerson(int _id, std::string _name) { id = _id, name = _name; }
    const int getId() const { return id; }
    const std::string getName() const { return name; }
};