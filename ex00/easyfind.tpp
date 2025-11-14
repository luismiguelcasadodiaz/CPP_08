#include <algorithm>    // std::find
#include <stdexcept>    // std::Out of range
template <typename T>
typename T::iterator easyfind(T & c , int n)
{
	typename T::iterator it;

	it =  std::find(c.begin(), c.end(), n);
	if (it == c.end())
		throw std::out_of_range("Exception Element not found in NON-CONST container");
	return it;
}
template <typename T>
typename T::const_iterator easyfind(T const & c , int const n)
{
	typename T::const_iterator it;

	it =  std::find(c.begin(), c.end(), n);
	if (it == c.end())
		throw std::out_of_range("Exception Element not found in CONST container");
	return it;
}



/* 
Sequence containers are:
vector
list
deque


Searching/Finding:
find // Find first occurrence of value
Returns BY VALUE an iterator to the first element in the range 
[first,last) that compares equal to val. 
If no such element is found, the function returns last.
*/
