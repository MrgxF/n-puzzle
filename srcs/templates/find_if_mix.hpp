#ifndef FIND_IF_CMP_HPP
# define FIND_IF_CMP_HPP

template<class C, class T>
C	find_if_mix(C start, C end,
								T const &val, bool (*f)( T, T))
{
	while (start != end)
	{
		if (f(*start, val))
			break ;
		start++;
	}
	return start;
}

#endif
