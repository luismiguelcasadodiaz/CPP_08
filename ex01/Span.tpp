#include <cstddef>
#include <sstream>


template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
	size_t count = std::distance(begin, end);
	if ( (count + this->_cur_nums) > this->_max_nums)
	{
		std::stringstream msg;
		msg << "Requested capacity (" << this->_max_nums << ") ";
		msg << "availability is not enough to fit " << count ;
		msg << " elements more.";
		throw std::length_error(msg.str());
	}


    InputIterator it;
	for (it = begin; it != end; it++)
	{
		int n = *it;
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

}

template<typename InputIterator>
void Span::addNumberSTL(InputIterator begin, InputIterator end)
{
	size_t count = std::distance(begin, end);
	if ( (count + this->_cur_nums) > this->_max_nums)
	{
		std::stringstream msg;
		msg << "Requested capacity (" << this->_max_nums << ") ";
		msg << "availability is not enough to fit " << count ;
		msg << " elements more.";
		throw std::length_error(msg.str());
	}
	this->_integers.insert(this->_integers.begin(),begin, end);
	this->_cur_nums += count;

}
