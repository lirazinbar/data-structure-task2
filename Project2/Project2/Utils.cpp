#include "Utils.h"
#include <iostream>
#include "BinarySearchTree.h"

void printResult(const Person& kPerson, int numComp, const char* algorithm) {
	std::cout << algorithm << ": " << kPerson.getId() << " " << kPerson.getName() << " " << numComp << " comparisons" << std::endl;
}

const Person& selectHeap(Person* persons, int n, int k, int& NumComp) {
	Heap heap = Heap(n);
	heap.buildHeap(persons, NumComp);
	Person* p = heap.selectHeap(k, NumComp);

	heap.makeEmpty();
	return *p;
}

const Person& BST(Person* persons, int n, int k, int& NumComp) {
	BinarySearchTree tree = BinarySearchTree();
	int i;

	for (i = 0; i < n; i++) {
		tree.insertPerson(persons+i, NumComp);
	}

	Person* p = tree.findPersonKth(k);

	tree.freeTree();
	return *p;
}