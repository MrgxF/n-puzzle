#ifndef	IHEURISTIC_HPP
# define IHEURISTIC_HPP

#include "Node.hpp"
#include <vector>

class IHeuristic{

public:
	virtual ~IHeuristic() {}

	virtual int					calculate(std::vector<int> const &current, Node const &goal) const = 0;
	virtual std::string const	getName() const = 0;
};

#endif

