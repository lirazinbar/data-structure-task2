#pragma once
#include <string>

class Person
{
    int id = 0;
    std::string name = "";

public:
    // Ctor
    Person() {};
    // Ctor
    Person(const int _id, const std::string& _name) : id(_id), name(_name) {};
    // Copy Ctor
    Person(const Person& p) : id(p.id), name(p.name) {};
    // Set the person's fields
    void setPerson(int _id, std::string _name) { id = _id, name = _name; }
    // Returns the person id
    const int getId() const { return id; }
    // Returns the person name
    const std::string getName() const { return name; }
};