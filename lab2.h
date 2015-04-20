#ifndef _LAB2_H_
#define _LAB2_H_

#include <forward_list>
#include <iostream>

using namespace std;

template <typename Type> 
struct Node
{
    Type value;
    Node* next;
    
    Node(Type val)
    :value(val), next(0)
    {}
};

bool isPrime(int i);
int primeCount(forward_list<int> lst);

template <typename Type> 
void listCopy(forward_list<Type> L, forward_list<Type>& P);
template <typename Type> 
void printLots(forward_list<Type> L, forward_list<Type> P);

template <typename Type> 
class List
{
    private:
        Node<Type>* head;
        Node<Type>* tail;
    
    public:
        List();
        void elementSwap(int pos);
        void push_back(Type T);
        void display();
        
        int size();
        
 
};

template <typename Type>
List<Type>::List()
:head(0), tail(0)
{}

template <typename Type> 
void List<Type>::elementSwap(int pos)
{
    if(size() == 0)
    {
        std::cout << "Error: The list is empty." << std::endl;
        return;
    }
    if(pos < 0)
    {
        std::cout << "Error: Position is negative." << std::endl;
        return;
    }
    if(pos + 1 > size())
    {
        std::cout << "Error: Out of bounds." << std::endl;
        return;
    }
    
    Node<Type>* temp = head;
    Node<Type>* temp2;
    for (int i = 0; i < pos - 1; ++i)
    {
        temp = temp->next;
    }
    
    if(pos == 0)
    {
        temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = temp;
        
        head = temp2;
    }
    else
    {
        temp2 = temp->next;
        if(temp2->next == tail)
        {
            temp->next = temp2->next;
            temp2->next = temp2->next->next;
            temp->next->next = temp2;
            tail = temp2;
        }
        else
        {
            temp->next = temp2->next;
            temp2->next = temp2->next->next;
            temp->next->next = temp2;
        }
    }

    if(temp2 == tail)
    {
        tail = temp;
    }
}

template <typename Type>
void List<Type>::push_back(Type T)
{
    if(head == 0)
    {
        Node<Type>* temp = new Node<Type>(T);
        head = temp;
        tail = head;
    }
    else
    {
        Node<Type>* temp = new Node<Type>(T);
        tail->next = temp;
        tail = temp;
    }
}

template <typename Type>
void List<Type>::display()
{
    Node<Type>* pos = head;
    
    for(pos = head; pos != 0; pos = pos->next)
    {
        std::cout << pos->value << " ";
    }
}

template <typename Type>
int List<Type>::size()
{
    if(head == 0)
    {
        return 0;
    }
    Node<Type>* pos = head;
    int counter = 0;
    for (pos = head; pos != 0; pos = pos->next)
    {
        counter++;
    }
    return counter;
}


template <typename Type> 
void listCopy(std::forward_list<Type> L, std::forward_list<Type>& P)
{
    typename std::forward_list<Type>::iterator iter = P.begin();
    std::forward_list<Type> N;
    
    int sz = 0;
    
    for(auto i = P.begin(); i != P.end(); ++i)
    {
       sz++;
    }
    for(int i = 0; i < sz - 1; ++i)
    {
        iter++;
    }
    
    for(auto it = L.begin(); it != L.end(); it++)
    {
        P.emplace_after(iter, *it);
    }
}

template <typename Type> 
void printLots(forward_list<Type> L, forward_list<Type> positions)
{
    typename forward_list<Type>::iterator it = L.begin();
    int counter = 0;
    for(auto pos = positions.begin(); pos != positions.end(); pos++)
    {
        while(counter != *pos)
        {
            counter++;
            it++;
        }
        if(counter == *pos)
        {
            std::cout << *it << " ";
        }

    }
}

#endif