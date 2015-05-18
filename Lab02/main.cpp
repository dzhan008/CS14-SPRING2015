/*
Name: David Zhang
SID: 861156108
Date: 4/18/15
*/

#include <iostream>
#include <forward_list>
#include "lab2.h"

using namespace std;

int main()
{
    //List should be 50, 9, 7, 5, 1
    std::string line = "------------------------------------------------";

    std::forward_list<int> lst;
    std::forward_list<int>lst2;
    std::forward_list<int>lst3;
    
    List<int> ele;
    
    forward_list<int>::iterator it = lst.begin();
    
    lst.push_front(1);
    lst.push_front(5);
    lst.push_front(7);
    lst.push_front(9);
    lst.push_front(50);
    
    //Lst2 should be 10, 40, 30, 20, 60
    
    lst2.push_front(60);
    lst2.push_front(20);
    lst2.push_front(30);
    lst2.push_front(40);
    lst2.push_front(10);
    
    
    //Lst3 should be 1,3,4
    lst3.push_front(4);
    lst3.push_front(3);
    lst3.push_front(1);
    
    //ele should be 5, 9, 7, 3
    ele.push_back(5);
    ele.push_back(9);
    ele.push_back(7);
    ele.push_back(3);
    std::cout << "Testing for primeCount..." << std::endl;
    std::cout << "Number of Prime #s: " << primeCount(lst) << std::endl;
    std::cout << line << std::endl;
    std::cout << "Testing for listCopy()" << std::endl;
    listCopy(lst2, lst);
    for(auto i = lst.begin(); i != lst.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl << line << std::endl;
    std::cout << "Testing for printLots()" << std::endl;
    printLots(lst2, lst3);
    std::cout << std::endl << line << std::endl;
    std::cout << "Testing for elementSwap()." << std::endl;
    std::cout << "Size: " << ele.size() << std::endl;
    std::cout << "Before: "; 
    ele.display();
    std::cout << std::endl;
    ele.elementSwap(3);
    std::cout << "After: ";
    ele.display();
    std::cout << std::endl;
    
    return 0;
}