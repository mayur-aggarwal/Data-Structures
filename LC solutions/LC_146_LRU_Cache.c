/**
 * @file LC_146_LRU_Cache.c
 * @brief LRU implementation using doubly linked list and hash map.
 *  https://leetcode.com/problems/lru-cache/description/?envType=problem-list-v2&envId=linked-list
 * Demonstrates the concept of Doubly Linked list and Hash Map.
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#define MAX_KEY 10001

typedef struct Node{
    int key;
    int value;
    struct Node *next;
    struct Node *prev;
}Node_t;

typedef struct {
    int capacity;
    int size;   
    Node_t head;
    Node_t tail;
    Node_t *map[MAX_KEY];
} LRUCache;

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache *obj = (LRUCache* )calloc(1, sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;

    obj->head.next = &obj->tail;
    obj->tail.prev = &obj->head;

    return obj; 	
}

void removeNode(Node_t *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void insertFront(LRUCache* obj, Node_t *node)
{
	node->next = obj->head.next;
	node->prev = &obj->head;

	obj->head.next->prev = node;
	obj->head.next = node;
}

int lRUCacheGet(LRUCache* obj, int key)
{
	Node_t *curr = obj->map[key];
	
	if(curr == NULL)
		return -1;

	removeNode(curr);
	insertFront(obj, curr);

	return curr->value;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
	Node_t *curr = obj->map[key];
	if(curr != NULL)
    {
        curr->value = value;
        removeNode(curr);
        insertFront(obj, curr);
        return;
    }
    if(obj->size == obj->capacity)
    {
        Node_t *victim = obj->tail.prev;
        obj->map[victim->key] = NULL;
        victim->prev->next = &obj->tail;
        obj->tail.prev = victim->prev;
        free(victim);
        obj->size--;
    }
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->key = key;
    node->value = value;
    insertFront(obj, node);
    obj->map[key] = node;
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    Node_t *curr = obj->head.next;
    while(curr != &obj->tail)
    {
        Node_t *next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
