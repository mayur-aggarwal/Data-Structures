#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TrieNode {
	struct TrieNode *children[26];
	bool iseof;
	int count;
	int linkdb;
};

struct db {
	char arr[13];
	int freq;
};

//1 DS
struct TrieNode mempool[100000];
unsigned int mempool_idx = 0;
//2 DS
struct db res[5001];
unsigned int res_idx = 1;

//char str[5000][13];
int str1[5000];
int str1_idx;

void init()
{
	mempool_idx = 0;
	res_idx = 1;
	str1_idx = 0;
	//root = getnode()
}

void search_allsubstr(struct TrieNode *root);

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = &mempool[mempool_idx++];
	pNode->iseof = false;
	pNode->count = 0;
	pNode->linkdb = 0;
	for (int i = 0; i < 26; i++)
	{
		pNode->children[i] = NULL;
	}

	return pNode;
}

void my_cpy(void *des, const char *src, int len)
{
	//char *s = src;
	char *d = (char *)des;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		d[i] = src[i];
	}
	d[i] = '\0';
}

// Building of Trie
void insert(struct TrieNode *root, const char key[])
{
	struct TrieNode *temp = root;
	//int len = strlen(key);
	//for (int i = 0; i < len; i++)
	int i = 0;
	while(key[i] != '\0')
	{
		int idx = key[i] - 'a';
		if (temp->children[idx] == NULL) 
		{
			temp->children[idx] = getNode();
		}
		temp->children[idx]->count++;
		printf("%c[%d]-", key[i], temp->children[idx]->count);
		temp = temp->children[idx];
		i++;
	}
	printf("\r\n");
	temp->iseof = true;
	if (!temp->linkdb)
	{
		my_cpy(res[res_idx].arr, key, strlen(key)+1);
		res[res_idx].freq = 1;
		temp->linkdb = res_idx++;
	}
	else
	{
		res[temp->linkdb].freq++;
	}

}

// Searching whole word in Trie
bool search(struct TrieNode *root, const char *key)
{
	struct TrieNode *temp = root;
	int len = strlen(key);	// a1b2c3
	for (int i = 0; i < len; i++)
	{
		int idx = key[i] - 'a';
		if (temp->children[idx] == NULL)
			return false;
		temp = temp->children[idx];
	}
	return (temp != NULL && temp->iseof);
}

// Searching Prefix & count
void search_substr(struct TrieNode *root, const char *key)
{
	struct TrieNode *temp = root;
	int len = strlen(key);
	for (int i = 0; i < len; i++)
	{
		int idx = key[i] - 'a';
		if (temp->children[idx] == NULL)
			return;
		temp = temp->children[idx];
	}
	str1_idx = 0;
	search_allsubstr(temp);
}

void search_allsubstr(struct TrieNode *root)
{
	struct TrieNode *temp = root;
	
	if (temp->linkdb)
	{
//		printf("%s %d\n ", res[str1_idx].arr, res[str1_idx].freq);
		str1[str1_idx++] = temp->linkdb;
	}

	for (int i = 0; i < 26; i++)
	{
		if (temp->children[i] != NULL)
		{
			search_allsubstr(temp->children[i]);
		}
	}
}

int main()
{
	const char *keys[] = { "sa","samsung","samsung","samsunglab", "sung","by","bye", "their" };
	int n = sizeof(keys) / sizeof(keys[0]);
	printf("size of n = %d\n", n);
	struct TrieNode *root = getNode();
	for (int i = 0; i < n; i++)
	{
		insert(root, keys[i]);
	}
	bool ret = search(root, "sa");
	if (ret)
		printf("YES\n");
	else
		printf("NO\n");
	ret = search(root, "these");
	if (ret)
		printf("YES\n");
	else
		printf("NO\n");
	search_substr(root, "sa");
//	printf("count = %d\n",search_substr(root, "sa"));
	for (int j = 0; j < str1_idx; j++)
		printf("%s %d\n", res[str1[j]].arr, res[str1[j]].freq);
	return 0;
}


