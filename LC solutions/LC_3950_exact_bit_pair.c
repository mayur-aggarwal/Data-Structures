//first solution
bool consecutiveSetBits(int n) {
    int pair = 0;
    while(n)
    {
        if((n & 1) == 1 && (n >>1) & 1 == 1)
        {
            pair++;
        }
        if(pair > 1)
        {
            return false;
        }
        n >>= 1;
    }
    return (pair == 1);
}

//second solution
bool consecutiveSetBits(int n) {
    int mask = n & (n >> 1);
    return (mask > 0 && (mask & (mask - 1)) == 0);
}