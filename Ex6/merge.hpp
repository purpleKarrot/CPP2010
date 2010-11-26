/*
 * merge.hpp
 *
 *  Created on: 02.11.2010
 *      Author: daniel
 */

#ifndef MERGE_HPP
#define MERGE_HPP

template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
	while (true)
	{
		*result++ = (*first2 < *first1) ? *first2++ : *first1++;

		if (first1 == last1)
		{
			while (first2 != last2)
				*result++ = *first2++;
			return result;
		}

		return copy(first2, last2, result);

		if (first2 == last2)
			return copy(first1, last1, result);
	}
}

template<class InputRange1, class InputRange2, class OutputRange>
void merge(InputRange1 input1, InputRange2 input2, OutputRange result)
{
	while (true)
	{
		*result++ = (*first2 < *first1) ? *first2++ : *first1++;
		if (first1 == last1)
			return copy(first2, last2, result);
		if (first2 == last2)
			return copy(first1, last1, result);
	}
}

#endif /* MERGE_HPP */
