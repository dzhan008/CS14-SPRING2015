#include <iostream>
#include <list>

using namespace std;

template <typename T> void merge_list(std::list<T>& a, std::list<T>& b); //Merges one list into another list in an alternating format.
template <typename T> void merge_sorted(std::list<T>& a, std::list<T>& b); //Merges one sorted list into another sorted list in a sorted format.
template <typename T> void rotate_counter(std::list<T>& a, int times); //Rotates a list in a certain amount of times.

int main()
{
    list<float>::iterator listD;
        
    list<float> one;
    list<float> two;
    list<float> four;
    list<std::string> three;
    
    one.push_back(1.5);
    one.push_back(2);
    one.push_back(2);
    one.push_back(4);
    one.push_back(6);
    one.push_back(8);
    one.push_back(10);
    
    two.push_back(1);
    two.push_back(3);
    two.push_back(5);
    two.push_back(7);
    two.push_back(9);
    
    three.push_back("HI");
    three.push_back("MEEP");
    three.push_back("This is dog");
    
    rotate_counter(three, -5);
    merge_sorted(one, two);
    //merge_list(one, two);
    
    for(listD = two.begin(); listD != two.end(); listD++)
    {
        std::cout << *listD << " ";
    }
    
}

template <typename T> void merge_list(std::list<T>& a, std::list<T>& b)
{
    for(typename list<T>::iterator i = b.begin(); i != b.end(); ++i) 
    {
        if(a.size() != 0) //Is a empty?
        {
            b.insert(i, a.front()); //Insert.
            a.pop_front();
        }
    }
    while(a.size() != 0) //Pushes everything back to b if there is still something in a.
    {
        b.push_back(a.front());
        a.pop_front();
    }
    return;
}

template <typename T> void merge_sorted(std::list<T>& a, std::list<T>& b)
{
    if(b.size() != 0) //Is b empty?
    {
        for(auto i = b.begin(); i != b.end(); ++i)
        {
            if(a.size() != 0)
            {
                while(*i > a.front() && a.size() != 0) //Is a's value less than b's?
                {
                        b.insert(i, a.front());
                        a.pop_front();
                }
                if (a.front() > b.back()) //Checks if a's value is actually bigger than the biggest value in b
                {
                    b.push_back(a.front());
                    a.pop_front();
                }
            }
        }
    }
    else //If b is empty, just push everything from a.
    {
        while(a.size() != 0)
        {
            b.push_back(a.front());
            a.pop_front();
        }
    }
}

template <typename T> void rotate_counter(std::list<T>& a, int times)
{
    if(times > 0)
    {
        for (unsigned i = 0; i < times; ++i) 
        {
            a.push_front(a.back()); //Push what's back to the front.
            a.pop_back(); //Remove the back.
        }
    }
}