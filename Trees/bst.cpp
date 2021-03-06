/**
 * @file bst.cpp
 * @brief insertion, search and deletion ops
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
 
#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* left, *right;
};

// newnode creation
struct node* newnode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

//searching element
struct node* search(struct node* root, int data)
{
	if(root->data == data || root == NULL)
		return root;
	if(data < root->data)
		return search(root->left, data);
	else
		return search(root->right, data);
	
}

//insertion
struct node* insert(struct node* node, int data)
{
	if(node == NULL)
		return newnode(data);
	if(data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

//finding inorder successor
struct node* minvaluenode(struct node* root)
{
	struct node* current = root;
	while(current && current->left != NULL)
		current = current->left;
	return current;
}

// deletion
struct node* deletenode(struct node* node, int data)
{
	if(node == NULL) return node;
	if(data < node->data)
		node->left = deletenode(node->left, data);
	else if(data > node->data)
		node->right = deletenode(node->right, data);
	else{
		// one child or no child case
		if(node->left == NULL)
		{
			struct node* temp = node->right;
			free(node);
			return temp;
		}
		else if(node->right == NULL)
		{
			struct node* temp = node->left;
			free(node);
			return temp;
		}
		// two child case
		struct node* tnode = minvaluenode(node->right);	//finding inorder successor
		node->data  = tnode->data;
		node->right = deletenode(node->right, tnode->data);
	}
	
	return node;
}

//sorted
void inorder(struct node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout << root->data << endl;
		inorder(root->right);
	}
}

int main()
{
	struct node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 80);
	inorder(root);
	struct node* pnode = search(root, 30);
	cout << "searched element : " << pnode->data << endl;
	root = deletenode(root, 30);
	cout << "After deletion \n";
	inorder(root);
	return 0;
}