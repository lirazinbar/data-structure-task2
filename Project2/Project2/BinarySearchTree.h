#pragma once
#include "TreeNode.h"

class BinarySearchTree {
	TreeNode* root;

	TreeNode* findPersonRec(int id, TreeNode* root);
	void deleteNode(TreeNode* nodeToDel);
	void insertNodeRec(TreeNode* node, TreeNode* root);
	TreeNode* getMax(TreeNode* node);
	TreeNode* findFather(TreeNode* node, TreeNode* root);
public:
	BinarySearchTree() : root(nullptr) {}
	TreeNode* findPerson(int id);
	void deletePerson(Person* p);
	void insertPerson(Person* p);
};
