#include <iostream>
#include <utility>
#include <queue>

class Coprimetree
{
    private:
        int k;
        std::priority_queue<std::pair<int, int>> sortq;
        void preorder_helper(int m, int n);
        void postorder_helper(int m, int n);
        void sortorder_helper(int m, int n);
        void sortorder_helper1(std::priority_queue<std::pair<int, int>>);
    public:
        Coprimetree(int);
        void preorder();
        void postorder();
        void sortorder();
        
};

Coprimetree::Coprimetree(int num)
:k(num)
{}

void Coprimetree::preorder()
{
    preorder_helper(2, 1);
    preorder_helper(3, 1);
}

void Coprimetree::preorder_helper(int m, int n)
{
    if(m + n > k)
    {
        return;
    }
    std::cout << m << " " << n << std::endl;
    preorder_helper((2 * m) - n, m);
    preorder_helper((2 * m) + n, m);
    preorder_helper(m + (2 * n), n);
    
    return;
}

void Coprimetree::postorder()
{
    postorder_helper(2, 1);
    postorder_helper(3, 1);
}

void Coprimetree::postorder_helper(int m, int n)
{
    if(m + n >= k)
    {
        return;
    }
    postorder_helper((2 * m) - n, m);
    postorder_helper((2 * m) + n, m);
    postorder_helper(m + (2 * n), n);
    std::cout << m << " " << n << std::endl;
}

void Coprimetree::sortorder()
{
    sortorder_helper(2, 1);
    sortorder_helper(3, 1);
    if(sortq.empty())
    {
        return;
    }
    std::priority_queue<std::pair<int, int>> tempq = sortq;
    sortorder_helper1(tempq);
    std::cout << tempq.top().first << " " << tempq.top().second << std::endl;
}

void Coprimetree::sortorder_helper(int m, int n)
{
    if(m + n >= k)
    {
        return;
    }
    std::pair<int, int> temp;
    temp.first = m;
    temp.second = n;
    sortq.push(temp);
    sortorder_helper((2 * m) - n, m);
    sortorder_helper((2 * m) + n, m);
    sortorder_helper(m + (2 * n), n);
    
}

void Coprimetree::sortorder_helper1(std::priority_queue<std::pair<int, int>> temp)
{
    if(temp.empty())
    {
        return;
    }
    temp.pop();
    sortorder_helper1(temp);
    std::cout << temp.top().first << " " << temp.top().second << std::endl;
    
    return;
}