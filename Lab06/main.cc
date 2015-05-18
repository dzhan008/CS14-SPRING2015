/*
Name: David Zhang
SID: 861156108
Date: 5/11/15
*/

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "selectionsort.h"

void vector_test();
void vector_test_2();
void list_test();
void vector_pair_test();
void vector_pair_test_1();

int main()
{
    list_test();
    vector_test();
    vector_test_2();
    vector_pair_test();
    vector_pair_test_1();
}

void list_test()
{
    std::list<float> hi;
    hi.push_back(50.2);
    hi.push_back(-12.3);
    hi.push_back(2.5);
    hi.push_back(23.9);   
    
    std::cout << "Pre: ";
    for(auto i: hi)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    selectionsort(hi);
    std::cout << "Post: ";
    for(auto i: hi)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;   
}

void vector_test()
{
    std::vector<int> hello;
    hello.push_back(50);
    hello.push_back(1);
    hello.push_back(5);
    hello.push_back(18);
    hello.push_back(20);
    hello.push_back(86);
    hello.push_back(23);
    hello.push_back(15);
    
    std::cout << "Pre: ";
    for(auto i: hello)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    selectionsort(hello);
    std::cout << "Post: ";
    for(auto i: hello)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void vector_test_2()
{
    std::vector<int> hello;
    hello.push_back(1);
    hello.push_back(1);
    hello.push_back(1);
    hello.push_back(1);
    hello.push_back(1);
    hello.push_back(1);
    hello.push_back(1);
    hello.push_back(1);
    
    std::cout << "Pre: ";
    for(auto i: hello)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    selectionsort(hello);
    std::cout << "Post: ";
    for(auto i: hello)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void vector_pair_test()
{
    std::vector<std::pair<int, std::string>> test;
    test.push_back(std::pair<int, std::string>(50, "what"));
    test.push_back(std::pair<int, std::string>(22, "meep"));
    test.push_back(std::pair<int, std::string>(11, "okay"));
    test.push_back(std::pair<int, std::string>(44, "lol"));
    test.push_back(std::pair<int, std::string>(88, "nani"));
    test.push_back(std::pair<int, std::string>(-22, "hi"));
    std::cout << "Pre: ";
    for(auto i: test)
    {
        std:: cout << "(" << i.first << "," << i.second << ") ";
    }
    std::cout << std::endl;
    selectionsort(test);
    std::cout << "Post: ";
    for(auto i: test)
    {
        std:: cout << "(" << i.first << "," << i.second << ") ";
    }
    std::cout << std::endl;
}

void vector_pair_test_1()
{
    std::vector<std::pair<int, int>> test;
    test.push_back(std::pair<int, int>(1, 2));
    test.push_back(std::pair<int, int>(3, -1));
    test.push_back(std::pair<int, int>(-1, 3));
    test.push_back(std::pair<int, int>(0, 0));
    test.push_back(std::pair<int, int>(2, 3));
    test.push_back(std::pair<int, int>(1, 2));
    test.push_back(std::pair<int, int>(1, -2));
    test.push_back(std::pair<int, int>(8, 10));

    std::cout << "Pre: ";
    for(auto i: test)
    {
        std:: cout << "(" << i.first << "," << i.second << ") ";
    }
    std::cout << std::endl;
    selectionsort(test);
    std::cout << "Post: ";
    for(auto i: test)
    {
        std:: cout << "(" << i.first << "," << i.second << ") ";
    }
    std::cout << std::endl;
}