#include "StateTree.h"

using namespace std;

// Extension of the Node struct, which includes 2 pointers, left and right.
TreeNode::TreeNode (string state, const string& confirmed, const string& deaths, string incidentRate)
: Node(state, confirmed, deaths, incidentRate) {
    left = nullptr;
    right = nullptr;
}

// Private version of the insert();
// Inserts a TreeNode into the Tree (Binary Search Tree).
void StateTree::privateInsert(TreeNode *currentNode, TreeNode *newNode)  {
    // Tree is empty.
    if (root == nullptr) {
        // Set the root of the tree to newNode.
        root = newNode;

    }
    // New value is less than current value.
    else if (newNode -> state < currentNode -> state) {
        // There is a left node.
        if (currentNode -> left != nullptr) {
            // Recursively check left subtree.
            privateInsert (currentNode -> left, newNode);
        }
        // There is no left node.
        else {
            // Insert new node as left child.
            currentNode -> left = newNode;
        }
    }
    else if (newNode -> state > currentNode -> state) {
        // There is a right node.
        if (currentNode -> right != nullptr) {
            // Recursively check right subtree.
            privateInsert (currentNode -> right, newNode);
        }
        // There is no right node.
        else {
            // Insert new node as right child
            currentNode -> right = newNode;
        }
    }
    // If it reaches this far, it's a duplicate and won't be added.
}

// Public version of the insert() which could be call by anyone,
// takes in the root of the tree as currentNode and insert node as newNode into the Tree.
void StateTree::insert(TreeNode * node) {
    privateInsert(root, node);
}

// Private version of the search();
// Return the node that has the state name user asked for.
Node * StateTree::privateSearch(TreeNode * currentNode, const string& state) {
    // If the currentNode is empty or the currentNode's state is the one we are looking for.
    if (currentNode == nullptr || currentNode -> state == state) {
        // Return the currentNode.
        return currentNode;
    }
    // Requested state comes before the current node
    if (state < currentNode -> state) {
        return privateSearch(currentNode -> left, state);
    }
    // requested state comes after the current node
    return privateSearch(currentNode -> right, state);
}

// Public version of the search() which could be call by anyone,
// takes in the root of the tree as currentNode.
Node StateTree::search(const string& state) {
    return *privateSearch(root, state);
}

// Private version of the printAll();
// calls the printNode() function on every node in the tree while accessing those nodes via inorder traversal.
void StateTree::privatePrintAll(TreeNode * currentNode) {
    // If the tree is empty, don't print anything.
    if (currentNode == nullptr) return;
    // Print current node.
    currentNode -> printNode();
    if (currentNode -> left != nullptr)
        // Print left node.
        privatePrintAll(currentNode -> left);
    if (currentNode -> right != nullptr)
        // Print right node.
        privatePrintAll(currentNode -> right);
}

// Public version of the printAll() which could be call by anyone,
// takes in the root of the tree as currentNode.
void StateTree::printAll(){
    privatePrintAll(root);
}