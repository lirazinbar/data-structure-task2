#pragma once
#include "Person.h"

struct TreeNode
{
    Person* data;
    TreeNode* left;
    TreeNode* right;

    //TreeNode(Person* _data, TreeNode* _left, TreeNode* _right) : data(_data), left(_left), right(_right) {}
    TreeNode(Person* _data) : data(_data), left(nullptr), right(nullptr) {}
};
//typedef struct tree
//{
//    TreeNode* root;
//} Tree;