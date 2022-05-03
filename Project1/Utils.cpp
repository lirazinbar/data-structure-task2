#include "Utils.h"
#include <iostream>

void printResult(const Person& kPerson, int numComp, const char* algorithm) {
	std::cout << algorithm << ": " << kPerson.getKey() << " " << kPerson.getName() << " " << numComp << " comparisons" << std::endl;
}