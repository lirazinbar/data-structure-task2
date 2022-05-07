#pragma once

#include "Person.h"

// Return a Person array with the data entered by the user
Person* getInput(int& n, int& k);
// Check if the id number has been chosen before 
void checkIdNumber(Person arr[], int index, int idNumber);
// Check if the name is valid
void checkName(std::string name);
// Prints an error message and exit program
void inputError();