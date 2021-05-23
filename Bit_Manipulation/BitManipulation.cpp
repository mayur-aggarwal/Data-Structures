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

#define SET_BIT(n, bit) (n|=(1<<bit))
#define CLEAR_BIT(n, bit) (n&=~(1<<bit))
#define TOGGLE_BIT(n, bit) (n^=(1<<bit))
#define CHECK_BIT(n, bit) (n&(1<<bit))
#define GET_BIT(n, bit) (n&(1<<bit))>>bit


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

/**
 *  @brief: Function to check if number is power of 2
 *  @param IN: unsigned int number
 *  @return: int
 */
bool isPowerTwo(unsigned int n)
{
	return (n && !(n & (n-1)));
}
 
void swapbits(unsigned int n, unsigned int p1, unsigned int p2)
{
	unsigned int bit1 = GET_BIT(n, p1);
	unsigned int bit2 = GET_BIT(n, p2);
	unsigned int x = bit1^bit2;
	x = (x << p1)|(x << p2);
	return x^n;
}

void reverse_naive(unsigned int n)
{
	unsigned int rev = n;
	int b = sizeof(n)*8-1;
	n >>= 1;
	while(n)
	{
		rev <<= 1;
		rev |= (n & 1);
		n >>= 1;
		b--;
	}
	rev <<= b;
	return rev;
}

void reverse_5lgN(unsigned int n)
{
	n = ((n >> 1)&0x55555555) | ((n & 0x55555555) << 1);
	n = ((n >> 2)&0x33333333) | ((n & 0x33333333) << 2);
	n = ((n >> 4)&0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4);
	n = ((n >> 8)&0x00FF00FF) | ((n & 0x00FF00FF) << 8);
	n = ((n >> 16)) | ((n) << 16);
}

int swapEvenOddBits(unsigned int n)
{
	return ((n & 0x55555555) << 1) | ((n & 0xAAAAAAAA)>>1);
}

void swapByte(unsigned int n)
{
	n = ((n & 0x000000FF) << 24) | ((n & 0x00FF00)<<8) | ((n & 0x00FF0000)>> 8) | ((n & 0xFF000000) >> 24);
}
