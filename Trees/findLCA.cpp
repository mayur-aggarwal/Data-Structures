/**
 * @file findLCA.cpp
 * @brief find the least common ancestor of 2 given nodes in a Binary Tree
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

/*
 *  structure for building binary tree
 */
struct Node{
	int data;	// holds the data
	struct Node *left, *right;	// left and right node pointer 
	Node(int d)
	{
		this->data = d;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/**
 *  @brief: Util function to find the LCA
 *  @param IN: struct Node* node, int n1, int n2
 *  @param OUT: bool &v1
 *  @param OUT: bool &v2
 *  @return struct Node*
 */
struct Node* findLCAUtil(struct Node* node, int n1, int n2, bool &v1, bool &v2)
{
	//base case
	if(node == NULL) return NULL;
	if(node->data == n1)
	{
		v1 = true;
		return node;
	}
	if(node->data == n2)
	{
		v2 = true;
		return node;
	}
	struct Node* left = findLCAUtil(node->left, n1, n2, v1, v2);	// recur in left
	struct Node* right = findLCAUtil(node->right, n1, n2, v1, v2);	// recur in right
	if(left && right) return node;
	return (left != NULL) ? left : right;
}


/**
 *  @brief: Validation function which tells the presence of each node in the tree
 *  @param IN: struct Node* root, int d
 *  @return: bool
 */
bool find(struct Node* node, int d)
{
	if(node == NULL)return false;
	if(node->data == d || find(node->left, d) || find(node->right, d))	//check for the data from LCA node
		return true;	// if present then return true
	return false;
}

/**
 *  @brief: Function calls util function to find the LCA and then validate the presence of each node in the tree
 *  @param IN: struct Node* root, int n1, int n2
 *  @return: struct Node* 
 */
struct Node* findLCA(struct Node* node, int n1, int n2)
{
	if(node == NULL) return NULL;
	bool v1 = false, v2 = false;
	struct Node* lca = findLCAUtil(node, n1, n2, v1, v2);	// find LCA
	if(v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))	// validata if both nodes are present in the tree
	{
		return lca;		// return LCA
	}
	return NULL;
}


int main()
{
    struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->left->left = new Node(8);
	//test case 1
	struct Node* lca = findLCA(root, 4, 5);
	if(lca != NULL) cout << "findLCA(4,5) = " << lca->data << endl;
	else 			cout << "data is not present in the tree\n";
	//test case 2
	lca = findLCA(root, 3, 8);
	if(lca != NULL) cout << "findLCA(3,8) = " << lca->data << endl;
	else 			cout << "data is not present in the tree\n";
	//test case 3
	lca = findLCA(root, 5, 10);
	if(lca != NULL) cout << "findLCA(5,10) = " << lca->data << endl;
	else 			cout << "data is not present in the tree\n";
	//test case 4
	lca = findLCA(root, 4, 7);
	if(lca != NULL) cout << "findLCA(4,7) = " << lca->data << endl;
	else 			cout << "data is not present in the tree\n";
    return 0;
}
