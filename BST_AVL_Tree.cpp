#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
	int lcnt;
	int rcnt;
	int cnt;
}node;

node* get_min(node* root);
node* get_max(node* root);

node mempool[1000001];
node* root = NULL;
int itr;

int get_rank(node* root, int key)
{
	if (root == 0)return 0;

	if (root->data == key)
	{
		if (root->cnt > 1)
		{
			return root->cnt + root->lcnt - 1;
		}
		return root->lcnt;
	}
	if (key < root->data)
	{
		if (!root->left)
			return 0;
		else
			get_rank(root->left, key);
	}
	else
	{
		if (!root->right)
			return 0;
		else
		{
			int rsize = get_rank(root->right, key);
			if(root->cnt > 1)
				return root->lcnt + rsize + root->cnt;
			return root->lcnt + 1 + rsize;
		}
	}
}



node* has1child(node* root)
{
	if (root == 0) return 0;
	node* child;
	if (root->left != 0 && root->right == 0)
	{
		child = root->left;
		*root = *child;
		child = 0;
		return root;
	}
	else if (root->left == 0 && root->right != 0)
	{
		child = root->right;
		*root = *child;
		child = 0;
		return root;
	}
	else
		return 0;
}

int hasleafnode(node* root)
{
	if (root == 0) return 0;
	if (root->left == 0 && root->right == 0)
		return 1;
	else
		return 0;
}

node* deletenode(node* root, int data)
{
	if (root == 0) return 0;
	if (data < root->data)
	{
		root->left = deletenode(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = deletenode(root->right, data);
	}
	else
	{
		if (root->cnt > 1)
		{
			root->cnt--;
			return root;
		}
		// #1 only leaf node
		if (hasleafnode(root))
		{
			return 0;
		}
		// #2 1 child node
		node* child = has1child(root);
			if (child != 0)
			{
				return child;
			}
			else // #3 2 child node
			{
				node* temp = get_min(root->right);
				root->data = temp->data;
				root->right = deletenode(root->right, data);
			}
	}
	return root;
}

node* search(node* root, int data)
{
	if (root == 0) return root;
	if (data == root->data) return root;
	else if (data < root->data) return search(root->left, data);
	else return search(root->right, data);
}

void predeccessor(node* root, node* &ans, int data)
{
	if (root == 0) return;
	if (data == root->data)
	{
		node* pMax = get_max(root->left);
		if (pMax) ans = pMax;
	}
	else if (data < root->data)
	{
		predeccessor(root->left, ans, data);
	}
	else
	{
		ans = root;
		predeccessor(root->right, ans, data);
	}
}

void successor(node* root, node* &ans, int data)
{
	if (root == 0) return;
	if (data == root->data)
	{
		node* pMin = get_min(root->right);
		if (pMin) ans = pMin;
	}
	else if (data < root->data)
	{
		ans = root;
		successor(root->left, ans, data);
	}
	else
	{
		successor(root->right, ans, data);
	}
}

int BST_Rank(int key)
{
	node* ans = NULL;
	predeccessor(root, ans, key);
	if (ans == NULL)
		return 0;
	else
		return get_rank(root, ans->data) + 1;
}

node* get_max(node* root)
{
	if (root == 0) return 0;
	node* ans = root;
	while (ans->right != 0)
	{
		ans = ans->right;
	}
	return ans;
}

node* get_min(node* root)
{
	if (root == 0) return 0;
	node* ans = root;
	while (ans->left != 0)
	{
		ans = ans->left;
	}
	return ans;
}

node* get_node(int data)
{
	node* pnode = &mempool[++itr];
	pnode->data = data;
	pnode->left = pnode->right = 0;
	pnode->lcnt = 0;
	pnode->rcnt = 0;
	pnode->cnt = 1;
	return pnode;
}

node* insert(node* root, int data)
{
	if (root == 0) return get_node(data);
	if (data == root->data)
	{
		root->cnt++;
		return root;
	}
	if (data < root->data)
	{
		root->left = insert(root->left, data);
		root->lcnt++;
	}
	else
	{
		root->right = insert(root->right, data);
		root->rcnt++;
	}
	return root;
}

void inorder(node* root)
{
	if (root)
	{
		inorder(root->left);
		if (root->cnt > 1)
		{
			for(int i = 0; i < root->cnt; i++)
				printf("%d ", root->data);
		}
		else
			printf("%d ", root->data);
		inorder(root->right);
	}
}

int main()
{
	root = insert(root, 40);
	root = insert(root, 60);
	root = insert(root, 45);
	root = insert(root, 65);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 50);
	root = insert(root, 70);
	root = insert(root, 35);
	root = insert(root, 5);
	root = insert(root, 35);
	root = insert(root, 20);
	root = insert(root, 65);
	root = insert(root, 50);
	inorder(root);
	printf("\n");
	int rank = 0;
	rank = BST_Rank(60);
	printf("No of nodes less than [60] are %d\n",rank);
	rank = BST_Rank(50);
	printf("No of nodes less than [50] are %d\n", rank);
	rank = BST_Rank(30);
	printf("No of nodes less than [30] are %d\n", rank);
	rank = BST_Rank(35);
	printf("No of nodes less than [35] are %d\n", rank);
	rank = BST_Rank(65);
	printf("No of nodes less than [35] are %d\n", rank);
	deletenode(root, 65);
	inorder(root);
	printf("\n");
	deletenode(root, 10);
	inorder(root);
	printf("\n");
	deletenode(root, 35);
	inorder(root);
	printf("\n");
	deletenode(root, 50);
	inorder(root);
	printf("\n");
	return 0;
}
