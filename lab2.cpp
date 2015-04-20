//Name: Michaella Sheng
//SID: 861162403
//Date: April 18, 2015

#include "lab2.h"

//Returns true if an int is prime
bool isPrime(int i)
{
    for(int factor = i-1; factor > 1; --factor)
    {
        if(i % factor == 0)
        {
            return false;
        }
    }
    return true;
}

//Counts the number of Nodes with prime data values
int primeCount(std::forward_list<int> lst)
{
    if(lst.empty())
    {
        return 0;
    }
    else if(isPrime(lst.front()))
    {
        lst.pop_front();
        return 1 + primeCount(lst);
    }
    else
    {
        lst.pop_front();
        return primeCount(lst);
    }
}