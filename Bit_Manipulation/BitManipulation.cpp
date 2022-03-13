/**
 * @file BitManipulation.cpp
 * @brief BitManipulation related functions
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>

using namespace std;

#define SWAP_XOR(a, b) (&(a) == &(b)) || (((a)^(b)) && ((b)^=(a)^=(b), (a)^=(b)))
#define SET_BIT(n, bit) (n|=(1<<bit))
#define CLEAR_BIT(n, bit) (n&=~(1<<bit))
#define TOGGLE_BIT(n, bit) (n^=(1<<bit))
#define CHECK_BIT(n, bit) (n&(1<<bit))
#define GET_BIT(n, bit) (n&(1<<bit))>>bit
#define CHAR_BITS 8

static const int S[] = {1, 2, 4, 8, 16};
static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

/**
 *  @brief: Function to count set bits in number
 *  @param IN: unsigned int number
 *  @return: unsigned int
 */
unsigned int CountSetBits(unsigned int n)
{
	unsigned int c;
	for(c = 0; n, c++)
	{
		n &= (n-1);
	}
	return c;
}

unsigned int count_set_bit_parallel(unsigned int n)
{
	int c;
	c = n - ((n >> S[0]) & B[0]);
	c = ((c >> S[1]) & B[1]) + (c & B[1]);
	c = ((c >> S[2])+c) & B[2];
	c = ((c >> S[3])+c) & B[3];
	c = ((c >> S[4])+c) & B[4];
	return c;
} 

/**
 *  @brief: Function to check if number is power of 2
 *  @param IN: unsigned int number
 *  @return: bool
 */
bool isPowerTwo(unsigned int n)
{
	return (n && !(n & (n-1)));
}

/*  Swapping individual bits with XOR   */
unsigned int swapbits(unsigned int n, unsigned int p1, unsigned int p2)
{
	unsigned int bit1 = GET_BIT(n, p1);
	unsigned int bit2 = GET_BIT(n, p2);
	unsigned int x = bit1^bit2;
	x = (x << p1)|(x << p2);
	return x^n;
}

/*  Swapping individual bits pair with XOR   */
unsigned int swap_bits_pair(unsigned int num, int p, int i, int j)
{
	unsigned int x = ((num >> i) ^ (num >> j)) & ((1 << p) - 1);
	return (num ^ ((x << i) | (x << j)));
}

unsigned int reverse_naive(unsigned int n)
{
	unsigned int rev = n;
	int b = sizeof(n)*8-1;
	n >>= 1;
	while(n)
	/*
		above two lines can be merged => for(n >>= 1; n; n>> =1)
	*/
	{
		rev <<= 1;
		rev |= (n & 1);
		n >>= 1;	// with for loop, this line will also be removed
		b--;
	}
	rev <<= b;
	return rev;
}

unsigned int reverse_5lgN(unsigned int n)
{
	n = ((n >> 1)&0x55555555) | ((n & 0x55555555) << 1);
	n = ((n >> 2)&0x33333333) | ((n & 0x33333333) << 2);
	n = ((n >> 4)&0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4);
	n = ((n >> 8)&0x00FF00FF) | ((n & 0x00FF00FF) << 8);
	n = ((n >> 16)) | ((n) << 16);
	return n;
}

int swapEvenOddBits(unsigned int n)
{
	return ((n & 0x55555555) << 1) | ((n & 0xAAAAAAAA)>>1);
}

void swapByte(unsigned int n)
{
	n = ((n & 0x000000FF) << 24) | ((n & 0x00FF00)<<8) | ((n & 0x00FF0000)>> 8) | ((n & 0xFF000000) >> 24);
}

int findmin(int a, int b)
{
	return (b^((a^b)&-(a<b)));
}

int findmax(int a, int b)
{
	return (a^((a^b)&-(a<b)));
}

int check_sign(int n)
{
	return ((n>0) - (n<0));	//1=>+ve, -1=>negative
}

int is_two_opp_sign(int a, int b)
{
	return (a^b)<0;
}

int rotateLeft(int n, int i)
{
	unsigned int c = sizeof(int)*CHAR_BITS;
	return ((n << i) | n >> (c-i));
}

int rotateRight(int n, int i)
{
	unsigned int c = sizeof(int)*CHAR_BITS ;
	return ((n >> i) | n << (c-i));
}

int clearFromMsbPos(int n, int i)
{
	int mask = (1<<i) - 1;
	n = n & mask;
	return n;
}

int clearFromLSBPos(int n, int i)
{
	int mask = (1<<i) - 1;
	mask = ~mask;
	n = n & mask;
	return n;
}


/*
Example: 
ResetBits_bw_i_j_pos(189, 2, 5)
	   				   	 5   210 -> bits 
mask = ffffffc3 [1111 1111 1111 1111 1111 1111 1100 0011]
res = 129
*/
int ResetBits_bw_i_j_pos(int num, int i, int j)
{
	// Assuming j > i
	int allones = ~0;
	int left = allones << (j+1);
	int right = (1 << i) - 1;
	int mask = left | right;
	int res = num & mask;
	return res;
}

/*
Example: 
SetBits_bw_i_j_pos(129, 2, 5)
	   				   5   210 -> bits 
mask = 3c [0000 0000 0000 0000 0000 0000 0011 1100]	// 60 in decimal
res = 189
*/
int SetBits_bw_i_j_pos(int num, int i, int j)
{
	// Assuming j > i
	int allones = ~0;
	int left = allones << (j+1);
	int right = (1 << i) - 1;
	int mask = left | right;
	mask ^= allones;
	int res = num | mask;
	return res;
}

unsigned int count_trailing_zeroes_naive(unsigned int n)
{
	unsigned int c;
	n = (n ^ (n-1)) >> 1;
	for(c = 0; n; c++)
	{
		n >>= 1;
	}
	return c;
}

unsigned int count_trailing_zeroes_binary_search(unsigned int n)
{
	unsigned int c;
	if(n == 0){
		c = 31;
		return c;
	}
	if(n & 0x01)	// first bit is 1 then return 0
	{
		c = 0;
	}
	else
	{
		c = 1;
		if((n & 0xffff) == 0)
		{
			n >>= 16;
			c += 16;
		}
		if((n & 0xff) == 0)
		{
			n >>= 8;
			c += 8;
		}
		if((n & 0xf) == 0)
		{
			n >>= 4;
			c += 4;
		}
		if((n & 0x3) == 0)
		{
			n >>= 2;
			c += 2;
		}
		c = c - (n & 1);
	}
	return c;
}
