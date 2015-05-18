/*
Name: David Zhang
SID: 861156108
Date: 5/11/15
*/
#include <utility>
#include <iostream>

#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

template<typename L>
void selectionsort(L &l)
{
    int swap_ctr = 0;
    int cpys = 0;
    
    for(auto i = l.begin(); i != l.end(); ++i)
    {


        typename L::iterator iter = i;
        for(auto j = i; j != l.end(); ++j)
        {
            if(*j < *iter)
            {
                iter = j;
            }
        }
        if(iter != i)
        {
            std::swap(*i, *iter);
            swap_ctr++;
        }
    }
    std::cout << cpys << " copies and " << swap_ctr * 3 << " moves" << std::endl;
}



#endif