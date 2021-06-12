/**
 * @file mirror_tree.cpp
 * @brief mirror or inverse the tree
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
 *  @brief: mirror or inverse the tree
 *  @param IN: root node
 *  @return struct Node*
 */
struct Node* mirrorTree(struct Node* root)
{
	if(root == NULL) return root;
	struct Node* temp;
	mirrorTree(root->left);
	mirrorTree(root->right);
	temp = root->right;
	root->right = root->left;
	root->left = temp;
	return root;
}