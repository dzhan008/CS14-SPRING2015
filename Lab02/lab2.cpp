#include <iostream>
#include <forward_list>
#include "lab2.h"




bool isPrime(int i)
{
    if(i == 1)
    {
        return false;
    }
    for(int factor = i - 1; factor > 1; factor--) //Start from the i - 1, since we know i % 0 is 0
    {
        if(i % factor == 0)   //If factor divide into i return false
        {
            return false;
        }
    }
    return true; //Otherwise return true.
}

int primeCount(forward_list<int> lst)
{
    if(lst.empty()) //If list's size is 0, return 0;
    {
        return 0;
    }
    else if(isPrime(lst.front())) //If the number is prime, pop the front, add one, call the function again.
    {
        lst.pop_front();
        return 1 + primeCount(lst);
    }
    else //If it isn't prime, pop the front and call the function again.
    {
        lst.pop_front();
        return primeCount(lst);
    }
    
}