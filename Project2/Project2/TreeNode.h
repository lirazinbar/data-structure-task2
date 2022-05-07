#pragma once
#include "Person.h"

struct TreeNode
{
    Person* data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Person* _data) : data(_data), left(nullptr), right(nullptr) {}
};