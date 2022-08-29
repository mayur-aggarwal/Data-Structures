/**
 * @file my_malloc.cpp
 * @brief Implements my malloc & free using static array
 *  or sbrk
 *
 * @bug No known bugs. Any improvements to this code would be welcomed.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>
#include <assert.h>
#include <stdio.h>

using namespace std;

#define MEM_SIZE 1000
#define USE_SBRK 0

#if USE_SBRK
#include <unistd.h>
#endif

static char mem_pool[MEM_SIZE];
static int mem_idx = 0;

typedef struct s_block {
	size_t size;
	size_t total_size;
	struct s_block* next;
	int free;
	int magic;  /* For Debug */
}block;

block* base = NULL;     /* Head pointer of linked list */

#define BLOCK_SIZE sizeof(block)

/**
 * @brief Get the available memory address from mem pool.
 *
 * @param[in] size - required size to allocate
 * @return allocated memory address
 */

void* get_mem(size_t s)
{
	if (mem_idx >= MEM_SIZE - 1)
	{
		cout << "No Memory is available\n";
		return NULL;
	}
	void* ptr = &mem_pool[mem_idx];
	mem_idx += (s+BLOCK_SIZE);
	return ptr;
}

/**
 * @brief Allocates the memory from the heap.
 *
 * @param[in] last - link the last mem block to curr allocated block
 * @param[in] size - required size to allocate
 * @return allocated memory address
 */

block* allocate_heap(block* last, size_t size)
{
	block* curr;
#if USE_SBRK
    void* p = sbrk(0);
#else
	void* p = get_mem(size);
#endif
	if (!p) return NULL;
	curr = (block*)p;
#if USE_SBRK    
    if(sbrk(BLOCK_SIZE + size) == (void*)-1) return NULL;
#endif
	cout << "Requested Bytes = " << size << endl;
	curr->size = size;
	curr->total_size = size + BLOCK_SIZE;
	curr->next = NULL;
	if (last)
	{
		last->next = curr;
	}
	curr->free = 0;
	curr->magic = 0x7777;
	return curr;
}

/**
 * @brief Find for memory block available
 *
 * @param[out] last - return the last available block
 * @param[in] size - required size to allocate
 * @return free block address
 */

block* find_block(block** last, size_t size)
{
	block* curr = base;
	while (curr && !(curr->free && curr->size >= size))
	{
		*last = curr;
		curr = curr->next;
	}
	return curr;
}

/**
 * @brief SPlits the available memory block
 *
 * @param[in] b - base address of available memory
 * @param[in] size - required size to allocate
 * @return void
 */

void split_block(block* b, size_t s)
{
	cout << __FUNCTION__ << " Enter !!\n";
	block* temp = (block*)((char*)b + s + BLOCK_SIZE + 1);  //base_addr + size + struct size
	temp->size = b->size - s - BLOCK_SIZE;
	temp->next = b->next;
	temp->free = 1; // mark it as free
	/*  Now update the base addr size */
	b->size = s;
	/*  Update the base next pointer to newly splitted node*/
	b->next = temp;
}

/**
 * @brief Allocates the memory from heap
 *
 * @param[in] size - size to allocate bytes
 * @return allocated address on success, NULL on fail
 */

void* my_malloc(size_t size)
{
	block* b;
	block* last;
	if (base)
	{
		/*  first search for any available free block */
		b = find_block(&last, size);
		if (b)
		{
			cout << "Free block is found, check if we can split\n";
			if ((b->size - size) >= (BLOCK_SIZE + 1))
			{
				split_block(b, size);
			}
			b->free = 0;
			b->magic = 0x2222;
		}
		else
		{
			b = allocate_heap(last, size);
			if (!b)
				return NULL;
		}
	}
	else
	{
		b = allocate_heap(NULL, size);
		if (!b) return NULL;
		base = b;
	}
	return (b);
}

block* get_mem_ptr(void* ptr)
{
	return ((block*)ptr);
}

void my_free(void* ptr)
{
	if (ptr != NULL)
	{
		block* b = get_mem_ptr(ptr);
		assert(b->free == 0);
		b->free = 1;
		b->magic = 0x5555;
	}
}

void print_memory_list(void* ptr)
{
	block* b = (block*)ptr;
}

void print_debug(void* ptr)
{
	block* b = (block*)ptr;
	cout << "Bytes = " << b->size << " allocated\n";
	cout << "Magic No = " << b->magic << endl;
}

int main()
{
	int* p1 = (int*)my_malloc(50);
	if (p1 != NULL)
	{
		cout << "memory is allocated\n";
		print_debug(p1);
	}
	int* p2 = (int*)my_malloc(30);
	if (p2 != NULL)
	{
		cout << "memory is allocated\n";
		print_debug(p2);
	}
	my_free(p1);
	print_debug(p1);
	int* p3 = (int*)my_malloc(20);
	if (p3 != NULL)
	{
		cout << "memory is allocated\n";
		print_debug(p1);
	}
	return 0;
}
