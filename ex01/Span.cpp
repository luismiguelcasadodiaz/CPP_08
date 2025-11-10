#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <sstream>
#include <stdexcept>
Span::Span(void)
{

}

Span::~Span(void)
{

}

Span::Span(Span const & other)
{
	(void)other;
}

Span & Span::operator=(Span const & other)
{
	(void)other;
	return *this;
}

Span::Span(unsigned int N) :
	_integers(std::vector<int>()),
	_max_nums(N),
	_cur_nums(0),
	_min(std::numeric_limits<int>::max()),
	_max(std::numeric_limits<int>::min())
{
	const size_t capacity = this->_integers.max_size() ; 
	if ( capacity < N)
	{
		std::stringstream msg;
		msg << "Requested capacity (" << N << ") ";
		msg << "exceeds vector<int>().max_size() (";
		msg << capacity << ")." ;
		throw std::length_error(msg.str());
	}
}

void Span::addNumber(int const n)
{
	if (this->_cur_nums == this->_max_nums)
	{
		std::stringstream msg;
		msg << "Requested capacity (" << this->_max_nums << ") ";
		msg << "is full.";
		throw std::length_error(msg.str());
	}
	this->_integers.push_back(n);
	if (n < this->_min)
	{
		this->_min = n;
	}
	if (this->_max < n)
	{
		this->_max = n;
	}
	_cur_nums++;
}


int Span::shortestSpan(void) const
{
	if (this->_cur_nums < 2)
	{
		std::stringstream msg;
		msg << "Can not calculate shortest span in a ";
		msg << "vector with "<< this->_cur_nums << "numbers";
		throw std::length_error(msg.str());
	}
    // Sort the vector first
    std::vector<int> sorted = this->_integers;
    std::sort(sorted.begin(), sorted.end());
    
    // Minimum difference must be between adjacent elements!
    int min_span = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < min_span)
            min_span = diff;
    }
    
    return min_span;

}

int Span::longestSpan(void) const
{
	if (this->_cur_nums < 2)
	{
		std::stringstream msg;
		msg << "Can not calculate shortest span in a ";
		msg << "vector with "<< this->_cur_nums << "numbers";
		throw std::length_error(msg.str());
	}
		return (this->_max - this->_min);
}

int Span::longestSpanSTL(void) const
{
	if (this->_cur_nums < 2)
	{
		std::stringstream msg;
		msg << "Can not calculate shortest span in a ";
		msg << "vector with "<< this->_cur_nums << "numbers";
		throw std::length_error(msg.str());
	}
	std::vector<int>::const_iterator maxi = std::max_element(this->_integers.begin(), this->_integers.end()); 
	std::vector<int>::const_iterator mini = std::min_element(this->_integers.begin(), this->_integers.end()); 
		return ( *maxi - *mini);
}
