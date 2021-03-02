#include "Manhattan.hpp"
#include <vector>

Manhattan::Manhattan():
	_name("Manhattan")
{
}

Manhattan::~Manhattan()
{
}

/*
 * For each element of the goal node, we look for its
 * corresponding value in the current node, then we calculate
 * the distance between the two points
*/
int		Manhattan::calculate(std::vector<int> const &map, Node const &goal) const
{
	int	cost = 0;
	int	size = goal._mapSize;

	std::vector<int> gmap = goal._map;

	for (int pos = 0 ; pos < size * size ; pos++)
	{
		if (map[pos] == 0)
			continue ;
		for (int gpos = 0 ; gpos < size * size ; gpos++)
		{
			if (map[pos] == gmap[gpos])
			{
				int valAbsolute = pos > gpos ? pos-gpos : gpos-pos;
				cost += valAbsolute / size + valAbsolute % size;
				break ;
			}
		}
	}

	return cost;
}

std::string	const	Manhattan::getName() const
{
	return _name;
}
