/*
Name: David Zhang
SID: 861156108
Date: 4/20/15
*/

#include <iostream>
#include <stack>
#include "lab3.h"

void fixed_s_test();
void flex_s_test();
void tower_of_hanoi_test();

int main()
{
    flex_s_test();
}

void fixed_s_test()
{
    TwoStackFixed<int> test(10, 5);

    test.pushStack1(5);
    test.pushStack1(4);
    test.pushStack1(7);
    test.pushStack1(9);
    test.pushStack1(59);
    test.pushStack1(8); //Tests for full stack
    
    test.pushStack2(1);
    test.pushStack2(3);
    test.pushStack2(5);
    test.pushStack2(9);
    test.pushStack2(999);
    test.pushStack2(599); //Tests for full stack
    
    for(int i = 0; i < 6; ++i) //Tests for empty stack
    {
        test.popStack1();
    }
    for(int i = 0; i < 6; ++i) //Tests for empty stack
    {
        test.popStack2();
    }

    test.display();
}

void flex_s_test()
{
    TwoStackOptimal<int> test1(10);
    
    test1.pushFlexStack1(5);
    test1.pushFlexStack1(1);
    test1.pushFlexStack1(3);
    test1.pushFlexStack1(8);
    test1.pushFlexStack1(7);
    test1.pushFlexStack1(9999);
    
    
    test1.pushFlexStack2(9);
    test1.pushFlexStack2(11);
    test1.pushFlexStack2(54);
    test1.pushFlexStack2(89);
    test1.pushFlexStack2(10); //Tests for full stack
    test1.pushFlexStack2(550);
    
    for(int i = 0; i < 8; ++i) //Tests for empty stack
    {
        test1.popFlexStack1();
    }
    
    test1.display();
}

void tower_of_hanoi_test()
{
    std::stack<int> A;
    std::stack<int> B;
    std::stack<int> C;
    
    A.push(3);
    A.push(2);
    A.push(1);
}