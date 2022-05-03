#pragma once

#include <string>

class Person {
	int idNumber = 0;
	std::string name;
public:
	// Empty ctor
	Person() {}
	// Ctor
	Person(int _idNumber, std::string _name) : idNumber(_idNumber), name(_name) {};
	void setPerson(int _idNumber, std::string _name) { idNumber = _idNumber, name = _name; }
	// Return the id number of the person, which is the key in the data structure
	int getKey() const { return idNumber; }
	// Retunr the name of the person (satellite data)
	const std::string& getName() const { return name; }
};

