#include "BinarySearchTree.h"

void BinarySearchTree::insertPerson(Person* p, int& NumComp) {
	TreeNode* newNode = new TreeNode(p);

	if (!root) root = newNode;
	else insertNodeRec(newNode, root, NumComp);
}

void BinarySearchTree::insertNodeRec(TreeNode* node, TreeNode* root, int& NumComp) {
	NumComp++;
	if (node->data->getId() < root->data->getId()) {
		if (root->left) {
			return insertNodeRec(node, root->left, NumComp);
		}
		else {
			root->left = node;
			return;
		}
	}

	if (root->right) {
		return insertNodeRec(node, root->right, NumComp);
	}
	else {
		root->right = node;
		return;
	}
}

TreeNode* BinarySearchTree::findPerson(int id) {
	return findPersonRec(id, root);
}

TreeNode* BinarySearchTree::findPersonRec(int id, TreeNode* root) {
	if (!root) return nullptr;
	if (root->data->getId() == id) return root;

	if (id < root->data->getId())
		return findPersonRec(id, root->left);
	return findPersonRec(id, root->right);
}

void BinarySearchTree::deletePerson(Person* p) {
	TreeNode* nodeToDel = findPerson(p->getId());
	deleteNode(nodeToDel);
}

void BinarySearchTree::deleteNode(TreeNode* nodeToDel) {
	if (nodeToDel->left && nodeToDel->right) {
		TreeNode* repNode = getMax(nodeToDel->left);
		*nodeToDel->data = *repNode->data;
		deleteNode(repNode);
	}
	else {
		TreeNode* father = findFather(nodeToDel, root);
		if (nodeToDel->left) {
			if (!father) root = nodeToDel->left;
			else father->left = nodeToDel->left;
		}
		else if (nodeToDel->right) {
			if (!father) root = nodeToDel->right;
			else father->right = nodeToDel->right;
		}
		delete nodeToDel;
	}
}

TreeNode* BinarySearchTree::getMax(TreeNode* node) {
	if (!node->right) return node;
	return getMax(node->right);
}

TreeNode* BinarySearchTree::findFather(TreeNode* node, TreeNode* root) {
	if (!root || root == node) return nullptr;
	if (root->left && root->left == node) return root;
	if (root->right && root->right == node) return root;

	if (node->data->getId() < root->data->getId()) return findFather(node, root->left);
	return findFather(node, root->right);
}

Person* BinarySearchTree::findPersonKth(int k) {
	int count = 0;
	return findPersonKthRec(root, k, count)->data;
}

TreeNode* BinarySearchTree::findPersonKthRec(TreeNode* root, int k, int& count) {
	if (!root) return nullptr;

	TreeNode* left = findPersonKthRec(root->left, k, count);
	
	if (left) return left;

	count++;

	if (count == k) return root;

	return findPersonKthRec(root->right, k, count);
}
