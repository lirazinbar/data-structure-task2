#pragma once
#include <string>

class Person
{
    int id = 0;
    std::string name = "";

public:
    Person(const int _id, const std::string& _name) : id(_id), name(_name) {}
    int getId() { return id; }
};