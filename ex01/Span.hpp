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
		int shortestSpan(void) const;
		int longestSpan(void) const;
	private:
		std::vector<int> integers;
};

#endif
