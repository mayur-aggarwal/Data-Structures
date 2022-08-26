#include <iostream>

using namespace std;

int findcomb(int floors, int eggs)
{
    if(eggs == 0 || floors == eggs)
    {
        return 1;
    }
    return findcomb(floors - 1, eggs)+findcomb(floors - 1, eggs - 1);
}

int calc_comb(int floors, int eggs)
{
    long long unsigned int s = 0;
    if(floors < eggs) eggs = floors;
    for(int i = 1; i <= eggs; i++)
    {
        s += findcomb(floors, i);
    }
    return s;
}

int findFloor(int n, int k)
{
    int low = 1, high = k;
    int sum = 0, mid = 1;
    while(low <= high)
    {
        mid = low + (high - low)/2;
        sum = calc_comb(mid, n);
        if(sum < k)
        {
            low = mid + 1;
        }
        else if(sum > k)
        {
            high = mid - 1;
        }
        else
            return mid;
    }
    return mid;
}

int main()
{
    int n = 2, k = 100;
    cout << findFloor(n, k) << endl;
    return 0;
}