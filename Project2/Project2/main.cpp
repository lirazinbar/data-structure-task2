#include "Person.h"
#include "Selection.h"
#include "Input.h"
#include "Heap.h"
#include "Utils.h"
#include <iostream>
//#include <cstdlib>
//#include <stdlib.h>

int main() {
	// We want to put the values in Selection as a class?
	int seed, n, k, numComp = 0;
	Person* personArr;
	Person kPerson;

	// The seed for srand which chosen by the user
	std::cin >> seed;
	srand(seed);
	personArr = getInput(n, k);

	kPerson = RandSelection(personArr, n, k, numComp);
	printResult(kPerson, numComp, "RandSelection");
	
	kPerson = selectHeap(personArr, n, k, numComp);
	printResult(kPerson, numComp, "selectHeap");

	numComp = 0;
	kPerson = BST(personArr, n, k, numComp);
	printResult(kPerson, numComp, "BST");

	delete[] personArr;
}