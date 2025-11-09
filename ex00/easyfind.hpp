#ifndef EASYFIND_HPP
#define EASYFIND_HPP
template <typename T>
typename T::iterator easyfind(T & c , int n);
template <typename T>
typename T::const_iterator easyfind(T const & c , int const n);
#include "easyfind.tpp"
#endif
