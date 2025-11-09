#include "easyfind.tpp"
#include <vector>
#include <list>
#include <deque>

#include <iostream>     // std::cout
#include <algorithm>    // std::find

int main () {
	int myints[] = { 10, 20, 30, 40 };
{
	std::vector<int> myvector (myints,myints+4);
  	std::vector<int>::iterator it;

  	it = ::easyfind<std::vector<int> >(myvector, 30);
  	if (it != myvector.end())
    	std::cout << "Element found in myvector: " << *it << '\n';
  	else
    	std::cout << "Element not found in myvector\n";
}
{
	std::list<int> mylist (myints,myints+4);
  	std::list<int>::iterator it;

  	it = ::easyfind<std::list<int> >(mylist, 31);
  	if (it != mylist.end())
    	std::cout << "Element found in mylist: " << *it << '\n';
  	else
    	std::cout << "Element not found in mylist\n";
}
{
	std::deque<int> mydeque (myints,myints+4);
  	std::deque<int>::iterator it;

  	it = ::easyfind<std::deque<int> >(mydeque, 30);
  	if (it != mydeque.end())
    	std::cout << "Element found in mydeque: " << *it << '\n';
  	else
    	std::cout << "Element not found in mydeque\n";
}
{
	std::vector<int> const myvector (myints,myints+4);
  	std::vector<int>::const_iterator it;

  	it = ::easyfind<std::vector<int> >(myvector, 30);
  	if (it != myvector.end())
    	std::cout << "Element found in myvector: " << *it << '\n';
  	else
    	std::cout << "Element not found in myvector\n";
}
{
	std::list<int> const mylist (myints,myints+4);
  	std::list<int>::const_iterator it;

  	it = ::easyfind<std::list<int> >(mylist, 31);
  	if (it != mylist.end())
    	std::cout << "Element found in mylist: " << *it << '\n';
  	else
    	std::cout << "Element not found in mylist\n";
}
{
	std::deque<int> const mydeque (myints,myints+4);
  	std::deque<int>::const_iterator it;

  	it = ::easyfind<std::deque<int> >(mydeque, 30);
  	if (it != mydeque.end())
    	std::cout << "Element found in mydeque: " << *it << '\n';
  	else
    	std::cout << "Element not found in mydeque\n";
}
  return 0;
}
