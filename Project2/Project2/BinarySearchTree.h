#pragma once
#include "TreeNode.h"

class BinarySearchTree {
	TreeNode* root;

	TreeNode* findPersonRec(int id, TreeNode* root);
	void deleteNode(TreeNode* nodeToDel);
	void insertNodeRec(TreeNode* node, TreeNode* root, int& NumComp);
	TreeNode* getMax(TreeNode* node);
	TreeNode* findFather(TreeNode* node, TreeNode* root);
	TreeNode* findPersonKthRec(TreeNode* root, int k, int& count);
	void freeTreeRec(TreeNode* root);
public:
	// Ctor
	BinarySearchTree() : root(nullptr) {}
	// Returns the person with the given id
	TreeNode* findPerson(int id);
	// Deletes the node of the given person from the tree
	void deletePerson(Person* p);
	// Inserts the given person and counts the amount of comparisons
	void insertPerson(Person* p, int& NumComp);
	// Returns the k person in the tree
	Person* findPersonKth(int k);
	// Free the Tree
	void freeTree();
};
