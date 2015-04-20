//Name: Michaella Sheng
//SID: 861162403
//Date: April 13, 2015

#ifndef LAB2_H
#define LAB2_H

#include <forward_list>
#include <iostream>

template<typename Type>
struct Node
{
    Type data;
    Node<Type>* next;
    Node<Type>(Type data) : data(data), next(0) {}
};

template<typename Type>
class List
{
    private:
        Node<Type>* head;
        Node<Type>* tail;
    public:
        int size() const;
        void display() const;
        void push_front(Type value);
        void elementSwap(int pos);
};

template<typename Type>
//Keeps a counter that increses by one everytime a Node is traversed.
int List<Type>::size() const
{
    int count = 0;
    for(Node<Type>* temp = head; temp != tail; temp = temp->next)
    {
        ++count;
    }
    return count;
}

template<typename Type>
void List<Type>::display() const
{
    if(head == 0)   //returns if list is empty
    {
        return;
    }
    for(Node<Type>* curr = head; curr != tail; curr = curr->next)
    {
        std::cout << curr->data << std::endl;
    }
}

template<typename Type>
void List<Type>::push_front(Type value)
{
    Node<Type>* temp = new Node<Type>(value);
    temp->next = head;
    head = temp;
    if (tail == 0)
    {
        tail = head;
    }
}
template<typename Type>
//Locates Node at the postions, then alters the links so that their order
//in the list is now swapped.
void List<Type>::elementSwap(int pos)
{
    //Checks for invalid position and list size
    if(pos < 0 || size() < 2 || pos >= size() - 1)
    {
        return; //Nothing is done to the list.
    }
    Node<Type>* temp_1 = head;
    for(int count = 0; ; ++count, temp_1 = temp_1->next)
    {
        if(count == pos - 1)
        {
            Node<Type>* temp_2 = temp_1->next;
            temp_1->next = temp_2->next;
            if(temp_2->next == tail)
            {
                tail->next = temp_2;
                temp_2->next = 0;
                tail = temp_2;
                return;
            }
            temp_2->next = temp_2->next->next;
            temp_1->next->next = temp_2;
            return;
        }
    }
}

bool isPrime(int i);
int primeCount(std::forward_list<int> lst);
template<typename Type>
//void listCopy(std::forward_list<Type> source, std::forward_list<Type>& dest);
void listCopy(std::forward_list<Type> source, std::forward_list<Type>& dest)
{
    //Nothing can be copied.
    if(source.empty())
    {
        return;
    }
    //Elements are simply "pushed back" where begin() would be.
    if(dest.empty())
    {
        auto it_2 = dest.before_begin();
        for(auto it_1 = source.begin(); it_1 != source.end(); ++it_1)
        {
            dest.emplace_after(it_2, *it_1);
        }
        return;
    }
    //Use count to calculate the final Node, since there is no size
    //function, set the iterator to the last Node, then add source's Nodes
    //onto the end by emplacing after the final dest Node.
    int count = 0;
    auto it_2 = dest.begin();
    for( ; it_2 != dest.end(); ++it_2, ++count)
    {}
    
    it_2 = dest.begin();
    for(int i = 0; i < count - 1; ++it_2, ++i)
    {}
    for(auto it_1 = source.begin(); it_1 != source.end(); ++it_1)
    {
        dest.emplace_after(it_2, *it_1);
    }
    
}
template<typename Type>
//void printLots(std::forward_list<Type> output, std::forward_list<int> pos);
void printLots(std::forward_list<Type> output, std::forward_list<int> pos)
{
    //Nothing will be printed in the case of an empty list
    if(pos.empty() || output.empty())
    {
        std::cout << "List empty." << std::endl;
        return;
    }
    //Keeps track of number of Nodes in the output list
    int size = 0;
    auto it_1 = output.begin();
    for(it_1 = output.begin(); it_1 != output.end(); ++it_1, ++size)
    {}
    //Sets an int to the value of the pos list, checks if it is greater than
    //the size of the output list, then an iterator iterates through the list
    //until it reaches the position stored by count, and outputs it
    int count = 0;
    for(auto it_2 = pos.begin(); count < size; ++it_2)
    {
        count = *it_2;
        if(count >= size)
        {
            return;
        }
        it_1 = output.begin();
        for(int i = 0; i < count; ++it_1, ++i)
        {}
        std::cout << *it_1 << std::endl;
    }
}

#endif
