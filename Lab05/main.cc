/*
Name: David Zhang
SID: 861156108
Date: 5/4/15
*/

#include <iostream>
#include <map>
#include "lab5.h"

void tree1()
{
    BST<int> test_tree;
    std::map<int, int> m;
    
    int test[1000];
    
    test_tree.insert(50); //Test tree from lab 5
    test_tree.insert(20);
    test_tree.insert(60);
    test_tree.insert(10);
    test_tree.insert(40);
    test_tree.insert(35);
    test_tree.insert(45);
    test_tree.insert(70);

    std::cout << "Testing tree from lab sample..." << std::endl;
    std::cout << "Part 1" << std::endl;
    test_tree.displayMinCover();
    std::cout << "Part 2" << std::endl;
    test_tree.findSumPath(test_tree.root, 180, test);
    std::cout << "Part 3" << std::endl;
    test_tree.vertSum(test_tree.root, 0, m);
    

}

void tree2()
{
    BST<int> test_tree;
    std::map<int, int> m;
    
    int test[1000];
    
    test_tree.insert(70);
    test_tree.insert(60);
    test_tree.insert(90);
    test_tree.insert(80);
    test_tree.insert(100);   
    std::cout << "Testing custom tree..." << std::endl;
    std::cout << "Part 1" << std::endl;
    test_tree.displayMinCover();
    std::cout << "Part 2" << std::endl;
    test_tree.findSumPath(test_tree.root, 180, test);
    std::cout << "Part 3" << std::endl;
    test_tree.vertSum(test_tree.root, 0, m);
    
}

int main()
{
    tree1();
    tree2();
}