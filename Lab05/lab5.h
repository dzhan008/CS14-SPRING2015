/*
Name: David Zhang
SID: 861156108
Date: 5/4/15
*/

#ifndef BST_H
#define BST_H
#define nil 0
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>

using namespace std;



// #define Value int // restore for testing.
template < typename Value >
class BST 
{
    
    
    class Node 
    { // binary tree node
    
        private:
            int counter; //Used to find the position of a specific node
        
        public:
            Value value;
            bool selected = false;
            
            Node* left;
            Node* right;

            Node( const Value v = Value() )
            : value(v), left(nil), right(nil)
            {}
        Value& content() { return value; }
        bool isInternal() { return left != nil && right != nil; }
        bool isExternal() { return left != nil || right != nil; }
        bool isLeaf() { return left == nil && right == nil; }
        
        int height() 
        {
            if(this == nil)
            {
                return 0;
            }
            if(isLeaf())
            {
                return 1;
            }
            if(left->height() > right->height() || left->height() == right->height())
            {

                return left->height() + 1;
            }
            else
            {
                return right->height() + 1;
            }
            
      
        // returns the height of the subtree rooted at this node
        }
        int size() 
        {
            if(this == nil)
            {
                return 0;
            }
            if(isLeaf())
            {
                return 1;
            }
            return left->size() + right->size() + 1;
        // returns the size of the subtree rooted at this node,
        }
        
        void preorder_prt()
        {
            if(this == nil)
            {
                return;
            }
            if(isLeaf())
            {
                std::cout << value << " ";
                return;
            }
            std::cout << value << " ";
            left->preorder_prt();
            right->preorder_prt();
            
            return;
            
        }
        
        void inorder_prt()
        {
            if(this == nil)
            {
                return;
            }
            if(isLeaf())
            {
                std::cout << value << " ";
                return;
            }
            left->inorder_prt();
            std::cout << value << " ";
            right->inorder_prt();
            
            return;
        }
        
        void postorder_prt()
        {
            if(this == nil)
            {
                return;
            }
            if(isLeaf())
            {
                std::cout << value << " ";
                return;
            }
            left->postorder_prt();
            right->postorder_prt();
            std::cout << value << " ";
        }
        
        void find_pos(int& n, std::vector<Node*>& vec)
        {
            if(this == nil)
            {
                return;
            }
            if(isLeaf())
            {
                if(n == 0)
                {
                    vec.push_back(this);
                    return;
                }
                n--;
                vec.push_back(this);
                return;
            }
            left->find_pos(n, vec);
            if(n == 0)
            {
                vec.push_back(this);
                return;
            }
            vec.push_back(this);
            n--;
            right->find_pos(n, vec);
            
            return;
        }
        
        /*                                                                                   LAB 5 FUNCTIONS HERE                                                                         */
        
        void minCover()
        {
            if(this == nil)
            {
                return;
            }
            if(isLeaf())
            {
                return;
            }
            left->minCover();
            right->minCover();
            if(this->left != nil && this->left->selected == false || this->right != nil && this->right->selected == false)
            {
                selected = true;
                return;
            }
            if(this->left != nil && this->left->selected || this->right != nil && this->right->selected)
            {
                selected = false;
                return;
            }
            return;
        }
        
        void minCover_h(int& sz)
        {
            if(this == nil)
            {
                return;
            }
            if(isLeaf())
            {
                return;
            }
            left->minCover_h(sz);
            if(this->selected)
            {
                std::cout << value << " ";
                sz++;
            }
            right->minCover_h(sz);
        }
        
        bool store_path(int& count, int sum, std::vector<int>& values)
        {
            if(this == nil)
            {
                return false;
            }
            if(isLeaf())
            {
                if(count + value == sum) 
                {
                    count += value;
                    values.insert(values.begin(),value); //Add the leaf's value to the vector.
                    return true;
                }
                return false;
            }
            if(count == sum) //Check
            {
                return true;
            }
            count += value;
            values.insert(values.begin(), value); //Initial insert
            if(count == sum) //Check
            {
                return true;
            }
            left->store_path(count, sum, values); //Check left side
            if(count == sum) //Check
            {
                return true;
            }
            right->store_path(count, sum, values); //Check right side
            if(count == sum) //Check
            {
                return true;
            }
            count -= value; //If the sum still cannot be found, we know that this node and its surrounding nodes will not make the full sum.
            values.erase(values.begin()); //We get rid of that node and look at the other side to see if a sum can be achieved.
            return false; //Final condition: When a sum cannot be reached at all.
        } 
        
        void display_SumPath(bool path_found, int buffer[])
        {
            if(!path_found) //If a path isn't found...
            {
                std:: cout << "0" << std::endl;
                return;
            }            

            for(int i = 0; buffer[i] != '\0'; ++i) //Output everything in the array.
            {
                std::cout << buffer[i] << " ";
            }
            std::cout << std::endl;
        }
        
        void vertSum_helper(int& offset, std::map<int,int>& m)
        {
            if(this == nil)
            {
                return;
            }
            if(isLeaf())
            {
                if(m.find(offset) == m.end()) //Is the offset index in the map already?
                {
                    m[offset] = value;
                    return;
                }
                m[offset] += value;
                return;
            }
            --offset; //Decrement the offset in the beginning to look for the left indexes
            left->vertSum_helper(offset, m);
            offset += 2; //Add offset by 2 to look for the right indexes
            right->vertSum_helper(offset, m);
            --offset; //Decrement once more to set the index back to its orginal position
            if(m.find(offset) == m.end()) //Place value of index into map
            {
                m[offset] = value;
            }
            else
            {
                m[offset] += value;
            }
            
            return;
        }
        /*                                                                                       END OF LAB 5 FUNCTIONS                                                                         */
        
    }; // Node
    
     //const Node* nil; // later nil will point to a sentinel node.
    
    private:

        //int count; //Probably not needed
        
        public:
            Node* root;
            int size() // size of the overall tree.
            {
                return root->size();
            }
            
            bool empty() { return size() == 0; }
            void print_node( const Node* n ) 
            {
                // Print the node’s value.
                std::cout << n->value;
            }

            bool search ( Value x )     // search for a Value in the BST and return true iff it was found
            {
                Node* iter = root;

                while(iter != nil)
                {//a minimum vertex cover
                    if (x == iter->value)
                    {
                        return true;
                    }
                    else if(x < iter->value)
                    {
                        iter = iter->left;
                    }
                    else
                    {
                        iter = iter->right;
                    }
                }
                return false;

            }
            void preorder()const 
            {
            // Traverse and print the tree one Value per line in preorder.
                root->preorder_prt();
            }  
            void postorder()const 
            {
            // Traverse and print the tree one Value per line in postorder
                root->postorder_prt();

            }
            void inorder()const 
            {
            // Traverse and print the tree one Value per line in inorder.
                root->inorder_prt();
            }
            Value& operator[] (int n) 
            {
                if(empty())
                {
                    std::cout << "Error: The tree is empty." << std::endl;
                    exit(0);
                }
                if(n < 0)
                {
                    std::cout << "Error: You have entered a negative number." << std::endl;
                    exit(0);
                }
                if(n > size())
                {
                    std::cout << "Error: You have gone out of bounds." << std::endl;
                    exit(0);
                }
                std::vector<Node*> vec;
                int pos = n;
                
                root->find_pos(n, vec);
                return vec.at(pos)->value;
            // returns reference to the value field of the n-th Node.
            }
            BST() : root(nil) {}
            void insert( Value X ) { root = insert( X, root ); 
            }
                Node* insert( Value X, Node* T ) {
                // The normal binary-tree insertion procedure ...
                if ( T == nil ) 
                {
                    T = new Node( X ); // the only place that T gets updated.
                } 
                else if ( X < T->value ) 
                {
                    T->left = insert( X, T->left );
                } 
                else if ( X > T->value ) 
                {
                    T->right = insert( X, T->right );
                } 
                else 
                {
                    T->value = X;
                }
                
                return T;
            }
            
            void displayMinCover()
            {
                int size = 0;
                
                root->left->minCover();
                root->right->minCover();
                root->left->minCover_h(size);
                root->right->minCover_h(size);
                std::cout << std::endl;
                std::cout << size << std::endl;
                
            }
            
            void findSumPath(Node* n, int sum, int buffer[])
            {
                int i = 0;
                int count = 0;
                std::vector<int>vals;
                bool path_found = true;
                
                path_found = n->store_path(count, sum, vals);

                for(i = 0; i < vals.size(); ++i)
                {
                    buffer[i] = vals.at(i);
                }
                buffer[i] = '\0';
                
                n->display_SumPath(path_found, buffer);
                
            }
            
            void vertSum(Node* node, int hd, std::map<int, int>& m)
            {
                node->vertSum_helper(hd, m); //Helper Function
                for(auto i : m)
                {
                    std::cout << i.second << " ";
                }
                std::cout << std::endl;
            }

};

#endif