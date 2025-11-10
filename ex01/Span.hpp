#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
class Span
{
	public:
		Span(void);
		~Span(void);
		Span(Span const & other);
		Span & operator=(Span const & other);
        Span(unsigned int N);
		void addNumber(int const n);
		template<typename InputIterator>
		void addNumber(InputIterator begin, InputIterator end);
		template<typename InputIterator>
		void addNumberSTL(InputIterator begin, InputIterator end);
		int shortestSpan(void) const;
		int longestSpan(void) const;
		int longestSpanSTL(void) const;		
	private:
		std::vector<int> _integers;
		unsigned int _max_nums;
		unsigned int _cur_nums;
		int _min;
		int _max;
};

#include "Span.tpp"
#endif

