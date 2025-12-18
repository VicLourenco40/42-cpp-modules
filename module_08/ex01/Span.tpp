#ifndef SPAN_TPP
#define SPAN_TPP

template<typename It>
void Span::addNumbers(It first, const It last)
{
	for (; first != last; first++)
		addNumber(*first);
}

#endif
