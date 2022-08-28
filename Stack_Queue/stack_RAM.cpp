/**
 * @file stack_RAM.cpp
 * @brief demontration of stack usage and stack guard
 *        verified this code in linux env.
 *
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <assert.h>

using namespace std;

#define STACKSIZE 8000
#define RESERVE_BOT 64
#define RESERVE_TOP 256
#define FILLSIZE (STACKSIZE - ((RESERVE_BOT)+(RESERVE_TOP)))
#define FILLPAT 0x41

void check_status(unisgned char* spbot)
{
    unsigned char* sptop = spbot-FILLSIZE;
    unsigned char* sp = sptop;
    ptrdiff_t s;
    int cnt = 0;
    sp = sptop;
    while(*sp == FILLPAT && sp != spbot)
    {
        printf("sp = %p  ", sp);
        sp++;
        cnt++;
    }
    cout << "cnt = " << cnt << endl;
    s = sp - sptop;
    cout << "Stack Usage upto " << (void *)sp << " used " << (FILLSIZE-s) << " bytes remianing" << endl; 
}

int main(int argc, char* argv[])
{
    int x;
    unsigned char *sp;
    sp = (unsigned char*)&x;
    sp -= RESERVE_TOP;  //start of stack address
    memset(sp-FILLSIZE, FILLPAT, FILLSIZE);
    check_status(sp);
    cout <<"Hello World\n" << (void*)sp << endl;
    check_status(sp);
}