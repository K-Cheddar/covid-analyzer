#pragma once
#include "Node.h"

using namespace std;

struct TreeNode : Node {
    TreeNode* left;
    TreeNode* right;

    TreeNode (string state, string confirmed, string deaths, string incidentRate);

};

class StateTree {
private:
    TreeNode * root; //  tree root

    void privateInsert(TreeNode* currentNode, TreeNode * newNode);

    Node * privateSearch(TreeNode * currentNode, const string& state);

    void privatePrintAll(TreeNode * currentNode);

public:
    void insert(TreeNode * node);
    Node search(const string& state);
    void printAll();
};
