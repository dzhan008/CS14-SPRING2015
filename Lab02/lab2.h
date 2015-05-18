/*
Name: David Zhang
SID: 861156108
Date: 4/18/15
*/

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
    //Error checking
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
    if(pos + 1 >= size())
    {
        std::cout << "Error: Out of bounds." << std::endl;
        return;
    }
    
    Node<Type>* temp = head; //We have a new Node temp to point to head.
    Node<Type>* temp2; //Temp2 points to nothing at first.
    for (int i = 0; i < pos - 1; ++i)
    {
        temp = temp->next; //We want to traverse temp to the position before the actual position. 
    }
    
    //Why do we point temp to the position before the actual position?
    //Because if we were to point it to the actual position we have NO way of pointing its previous node
    //to anywhere. That node will just point to the actual position and not the position afterwards.
    
    if(pos == 0) //If the position is just head...
    {
        temp2 = temp->next; //Make temp2 head->next
        temp->next = temp2->next; //temp's next value is temp2's head value
        temp2->next = temp; //Temp2's next value is just temp (what used to be head)
        
        head = temp2; //Make head point to temp2.
    }
    else
    {
        temp2 = temp->next; //Temp2 is the position.
        if(temp2->next == tail) //Is temp2's next node the tail? (Meaning, is the pos + 1 value tail?)
        {
            temp->next = temp2->next;  //Temp's ext node points to tail.
            temp2->next = temp2->next->next; //The new tail's next node points to NULL
            temp->next->next = temp2; //Temp's next's node's next node is temp2.
            tail = temp2; //Tail is now temp2.
        }
        else //For any other cases
        {
            temp->next = temp2->next; //Temp's next node is position + 1's node
            temp2->next = temp2->next->next; //Pos's 1's next node is it's next node.
            temp->next->next = temp2; //Switch the nodes here.
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
    if(head == 0) //If head is 0...
    {
        return 0; 
    }
    Node<Type>* pos = head;
    int counter = 0; //Set a counter for size
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
    
    for(auto i = P.begin(); i != P.end(); ++i) //Creates the size for P.
    {
       sz++;
    }
    for(int i = 0; i < sz - 1; ++i) //Pushes the iterator of P to its end.
    {
        iter++;
    }
    
    for(auto it = L.begin(); it != L.end(); it++) //Pushes back the items in L to P in reverse form.
    {
        P.emplace_after(iter, *it);
    }
}

template <typename Type> 
void printLots(forward_list<Type> L, forward_list<Type> positions)
{
    typename forward_list<Type>::iterator it = L.begin(); //Create an iterator for L.
    int counter = 0; //Set a counter.
    for(auto pos = positions.begin(); pos != positions.end(); pos++)
    {
        while(counter != *pos) //As long as counter is not equal to the position...
        {
            counter++; //Increment counter.
            it++; //Traverse through L UNTIL we reach the value of *pos.
        }
        if(counter == *pos) //Is counter equal to *pos (The position of L?)
        {
            std::cout << *it << " "; //Output the iterator
        }

    }
}

#endif