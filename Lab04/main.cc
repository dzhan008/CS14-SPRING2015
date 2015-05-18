#include <iostream>
#include <cstdlib>
#include "lab4.h"

int main( int argc, char* argv[] )
{
    if(argc != 2)
    {
        std::cout << "Usage: main.cc <k>" << std::endl;
        exit(-1);
    }
    if(atoi(argv[1]) < 0)
    {
        std::cout << "Error: k is negative." << std::endl;
        exit(-1);
    }
    Coprimetree a(atoi(argv[1]));
    std::cout << "Preorder Form: " << std::endl;
    a.preorder();
    std::cout << std::endl;
    std::cout << "Postorder Form: " << std::endl;
    a.postorder();
    std::cout << std::endl;
    std::cout << "Sorted Form: " << std::endl;
    a.sortorder();
}