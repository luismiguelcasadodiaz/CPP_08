#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{


    {//deque
        std::cout << "Deque Mutant Stack" << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "top " << mstack.top() << std::endl;
        mstack.pop();
        std::cout  << "Size " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }


    { //vector
        std::cout << "vector Mutant Stack" << std::endl;
        MutantStack<int, std::vector<int> > mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "top "  << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
        MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::vector<int> s(mstack.begin(), mstack.end());
        std::vector<int>::iterator itv = s.begin();
        std::vector<int>::iterator itev = s.end();
        std::cout << "content of vector's Mutant Stack" << std::endl;
        while (itv != itev)
        {
            std::cout << *itv << std::endl;
            ++itv;
        }        

    }

      {//list

        std::cout << "list Mutant Stack" << std::endl;

        MutantStack<int, std::list<int> > mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "top "  << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int, std::list<int> >::iterator it = mstack.begin();
        MutantStack<int, std::list<int> >::iterator ite = mstack.end();
        ++it;
        --it;        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        //std::vector<int> s(mstack);

    }
    return 0;
}
