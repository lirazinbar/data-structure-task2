#pragma once

#include <string>

class Person {
	int idNumber;
	std::string name;
public:
	// Empty ctor
	Person(int _idNumber, std::string _name) : idNumber(_idNumber), name(_name) {};
	// Return the id number of the person, which is the key in the data structure
	int getKey() const { return idNumber; }
	// Retunr the name of the person (satellite data)
	const std::string& getName() const { return name; }
};

