/*
Name: David Zhang
SID: 861156108
Date: 4/20/15
*/

#ifndef _LAB2_H_
#define _LAB2_H_

#include <iostream>
#include <stack>

template <typename T>
class TwoStackFixed
{
    private:
        T* stack;
        int border;
        int top1; //Index of Top of Stack 1
        int top2; //Index of Top of Stack 2
        int sz; //Actual size of array
        
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
    
    public:
        TwoStackFixed(int size, int maxtop);
        ~TwoStackFixed();
    
        void pushStack1(T value);
        void pushStack2(T value);
        void display();
        
        T popStack1();
        T popStack2();
};

template <typename T>
class TwoStackOptimal
{
    private:
        T* flex_stack;
        int top1;
        int top2;
        int sz;
        int stk1_sz;
        int stk2_sz;
        
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
    public:
        TwoStackOptimal(int size);
        ~TwoStackOptimal();
        
        void pushFlexStack1(T value);
        void pushFlexStack2(T value);
        void display();
        
        T popFlexStack1();
        T popFlexStack2();
        

};

                                                        // TWO STACK FIXED FUNCTIONS BEGIN //

template <typename T>
TwoStackFixed<T>::TwoStackFixed(int size, int maxtop)
{
    sz = size + 1;
    stack = new T[sz]; //Generates a new stack with size + 1. The extra element is used to be the middle point for each stack.
    border = maxtop; //We will store the border's index this way. In this, we ASSUME that maxtop indicates the maximum of the first stack.
    top1 = -1; //Top is automatically set to -1, but this means that even on an empty list top can be accessed...
    top2 = sz; //Size is added twice to check for out of boundary cases. (We set it to this to account for empty stacks.)
    for(int i = 0; i < size + 1; ++i)
    {
        stack[i] = T();
    }
}

template <typename T>
TwoStackFixed<T>::~TwoStackFixed()
{
    delete []stack;
}

template <typename T>
void TwoStackFixed<T>::pushStack1(T value)
{
    if(isFullStack1())
    {
        std::cout << "Error: Stack 1 is full." << std::endl;
        return;
    }
    if(isEmptyStack1())
    {
        top1 = 0;
        stack[top1] = value; //Top 1 assumed to be 0 when initialized.
        return;
    }
    top1++;
    stack [top1] = value;
}

template <typename T>
void TwoStackFixed<T>::pushStack2(T value)
{
    if(isFullStack2())
    {
        std::cout << "Error: Stack 2 is full." << std::endl;
        return;
    }
    if(isEmptyStack2())
    {
        top2 = sz - 1;
        stack[top2] = value; //Top 2 assumed to be sz - 1 when initialized.
        return;
    }
    top2--;
    stack[top2] = value;
}

template <typename T>
void TwoStackFixed<T>::display()
{
    if(isEmptyStack1() && isEmptyStack2())
    {
        std::cout << "Both stacks are empty." << std::endl;
    }
    if(!isEmptyStack1())
    {
        std::cout << "Stack 1" << std::endl;
        for(int i = top1; i > -1; --i)
        {
            std::cout << stack[i] << std::endl;
        }
    }
    if(!isEmptyStack2())
    {
        std::cout << "Stack 2" << std::endl;
        for(unsigned i = top2; i < sz; ++i)
        {
            std::cout << stack[i] << std::endl;
        }
    }
}

template <typename T>
T TwoStackFixed<T>::popStack1()
{
    T temp = stack[top1];
    if(isEmptyStack1())
    {
        std::cout << "Error: Stack 1 is empty." << std::endl;
        return temp;
    }
    stack[top1] = T();
    top1--;
    
    return temp;
}

template <typename T>
T TwoStackFixed<T>::popStack2()
{
    T temp = stack[top2];
    if(isEmptyStack2())
    {
        std::cout << "Error: Stack 2 is empty." << std::endl;
        return temp;
    }
    stack[top2] = T();
    top2++;
    
    return temp;
}

template <typename T>
bool TwoStackFixed<T>::isFullStack1()
{
    if(top1 + 1 == border) //Is top1's next index the border? If so, then stack 1 is full.
    {
        return true;
    }
    return false;
}

template <typename T>
bool TwoStackFixed<T>::isFullStack2()
{
    if(top2 - 1 == border) //Is top2's next index  the border? If so, then stack 2 is full.
    {
        return true;
    }
    return false;
}

template <typename T>
bool TwoStackFixed<T>::isEmptyStack1()
{
    if(top1 == -1)
    {
        return true;
    }
    return false;
}

template<typename T>
bool  TwoStackFixed<T>::isEmptyStack2()
{
    if(top2 == sz)
    {
        return true;
    }
    return false;
}

                                                        // TWO STACK FIXED FUNCTIONS END //


                                                        // TWO STACK OPTIMAL FUNCTIONS BEGIN //


template <typename T>
TwoStackOptimal<T>::TwoStackOptimal(int size)
{
    sz = size;
    stk1_sz = 0;
    stk2_sz = 0;
    flex_stack = new T[sz]; //Generates a new stack with sz.
    top1 = -1; //Top is automatically set to -1, but this means that even on an empty list top can be accessed...
    top2 = sz; //Size is added twice to check for out of boundary cases. (We set it to this to account for empty stacks.)
    for(int i = 0; i < sz; ++i)
    {
        flex_stack[i] = T();
    }
}

template <typename T>
TwoStackOptimal<T>::~TwoStackOptimal()
{
    delete []flex_stack;
}

template <typename T>
void TwoStackOptimal<T>::pushFlexStack1(T value)
{
    if(isFullStack1())
    {
        std::cout << "Error: Stack 1 is full." << std::endl;
        return;
    }
    if(isEmptyStack1())
    {
        top1 = 0;
        stk1_sz++;
        flex_stack[top1] = value; //Top 1 assumed to be 0 when initialized.
        return;
    }
    top1++;
    stk1_sz++;
    flex_stack[top1] = value;

}

template <typename T>
void TwoStackOptimal<T>::pushFlexStack2(T value)
{
    if(isFullStack2())
    {
        std::cout << "Error: Stack 2 is full." << std::endl;
        return;
    }
    if(isEmptyStack2())
    {
        top2 = sz - 1;
        stk2_sz++;
        flex_stack[top2] = value; //Top 2 assumed to be sz - 1 when initialized.
        return;
    }
    top2--;
    stk2_sz++;
    flex_stack[top2] = value;
}

template <typename T>
void TwoStackOptimal<T>::display()
{
    if(isEmptyStack1() && isEmptyStack2())
    {
        std::cout << "Both stacks are empty." << std::endl;
    }
    if(!isEmptyStack1())
    {
        std::cout << "Stack 1" << std::endl;
        for(int i = top1; i > -1; --i)
        {
            std::cout << flex_stack[i] << std::endl;
        }
    }
    if(!isEmptyStack2())
    {
        std::cout << "Stack 2" << std::endl;
        for(unsigned i = top2; i < sz; ++i)
        {
            std::cout << flex_stack[i] << std::endl;
        }
    }
}

template <typename T>
T TwoStackOptimal<T>::popFlexStack1()
{
    T temp = flex_stack[top1];
    if(isEmptyStack1())
    {
        std::cout << "Error: Stack 1 is empty." << std::endl;
        return temp;
    }
    flex_stack[top1] = T();
    top1--;
    stk1_sz--;
    
    return temp;
}

template <typename T>
T TwoStackOptimal<T>::popFlexStack2()
{
    T temp = flex_stack[top2];
    if(isEmptyStack2())
    {
        std::cout << "Error: Stack 2 is empty." << std::endl;
        return temp;
    }
    flex_stack[top2] = T();
    top2++;
    stk2_sz--;
    
    return temp;
}

template <typename T>
bool TwoStackOptimal<T>::isFullStack1()
{
    if(stk1_sz + stk2_sz == sz) //Is top1's next index the border? If so, then stack 1 is full.
    {

        return true;
    }
    return false;
}

template <typename T>
bool TwoStackOptimal<T>::isFullStack2()
{
    if(stk1_sz + stk2_sz == sz) //Is top2's next index  the border? If so, then stack 2 is full.
    {
        return true;
    }
    return false;
}

template <typename T>
bool TwoStackOptimal<T>::isEmptyStack1()
{
    if(top1 == -1)
    {
        return true;
    }
    return false;
}

template<typename T>
bool  TwoStackOptimal<T>::isEmptyStack2()
{
    if(top2 == sz)
    {
        return true;
    }
    return false;
}

// TOWER OF HANOI FUNCTIONS

template <typename T>
void showTowerStates(int n, std::stack<T>& A, std::stack<T>& B, std::stack<T>& C)
{
    std::string a = 'A';
    std::string b = 'B';
    std::string c = 'C';
    
    if(n == 0)
    {
        moveDisk(A, C);
        return; //Done!
    }
    
    return; //Could not figure out.
}

template <typename T>
void moveDisk(std::stack<T>& src, std::stack<T>& dest)
{
    T temp;
    temp = src.front();
    src.pop();
    dest.push(temp);
}


#endif