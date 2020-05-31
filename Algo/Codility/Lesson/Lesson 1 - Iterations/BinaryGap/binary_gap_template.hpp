#ifndef CODILITY_LESSON_1_BINARY_GAP_TEMPLATE_HPP
#define CODILITY_LESSON_1_BINARY_GAP_TEMPLATE_HPP

#if __cplusplus >= 201103L
#include <type_traits>
#endif

namespace codility {
namespace lesson_1 {

template<typename integer_type>
#if __cplusplus >= 201402L
constexpr
#endif
integer_type binary_gap(integer_type input)
{
#if __cplusplus >= 201103L
	static_assert(std::is_integral<integer_type>::value, "The input type is not an integral type.");
#endif
	const integer_type zero = 0;
	const integer_type two = 2;
	integer_type integer = input;
	integer_type remainder = zero;

	// perform repeated divisions by 2 and check the remainder after each division

	// skip the trailing binary zeroes
	while (integer != zero)
	{
		remainder = integer % two;
		integer /= two;
		if (remainder != zero)
		{
			break;
		}
	}

	integer_type adjacent_zero_count = zero;
	integer_type max_adjacent_zero_count = adjacent_zero_count;
	bool previous_bit_is_zero = false;

	// determine the maximum number of zero bits between two one bits
	while (integer != zero)
	{
		remainder = integer % two;
		integer /= two;

		if (zero == remainder)
		{
			++adjacent_zero_count;
			previous_bit_is_zero = true;
		}
		else if (previous_bit_is_zero)
		{
			if (adjacent_zero_count > max_adjacent_zero_count)
			{
				max_adjacent_zero_count = adjacent_zero_count;
			}

			adjacent_zero_count = zero;
			previous_bit_is_zero = false;
		}
	}

	return max_adjacent_zero_count;
}

} // namespace lesson_1
} // namespace codility

#endif
