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
public:
	BinarySearchTree() : root(nullptr) {}
	TreeNode* findPerson(int id);
	void deletePerson(Person* p);
	void insertPerson(Person* p, int& NumComp);
	Person* findPersonKth(int k);
};
