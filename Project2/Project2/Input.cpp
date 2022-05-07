#include "Input.h"
#include <iostream>
#include <sstream>
#include <vector>

Person* getInput(int& n, int& k) {
	std::cin >> n;
	if (n < 1) {
		inputError();
	}
	Person* personArr = new Person[n];
	for (int i = 0; i < n; i++) {
		int idNumber;
		std::string name;
		std::cin >> idNumber;
		checkIdNumber(personArr, i, idNumber);
		// Skip the back space between the number and the name
		std::getchar();
		std::getline(std::cin, name);
		checkName(name);
		personArr[i].setPerson(idNumber, name);
	}
	std::cin >> k;
	// k is smaller or equal to n
	if (k > n || k < 1) {
		inputError();
	}
	return personArr;
}

void checkIdNumber(Person arr[], int index, int idNumber) {
	// Check the previous persons if the new idNumber repeats
	for (int i = 0; i < index; i++) {
		if (arr[i].getId() == idNumber)
			inputError();
	}
}

void checkName(std::string name) {
	std::string tmp;
	std::stringstream str_stream(name);
	std::vector<std::string> firstLastNames;

	while (str_stream >> tmp)
		firstLastNames.push_back(tmp);
	// Exit if the name is not composed of first name and last name only
	if (firstLastNames.size() != 2) {
		exit(-1);
	}
}

void inputError() {
	std::cout << "Invalid input!";
	exit(1);
}