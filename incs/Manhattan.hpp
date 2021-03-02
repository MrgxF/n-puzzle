#ifndef	MANHATTAN_HPP
# define MANHATTAN_HPP

# include "IHeuristic.hpp"

# include <string>
#include <vector>

class Manhattan : public IHeuristic{

private:
	std::string				_name;

public:
	Manhattan();
	virtual ~Manhattan();

	virtual int					calculate(std::vector<int> const &map, Node const &goal) const;
	virtual std::string const	getName() const;

};

#endif

