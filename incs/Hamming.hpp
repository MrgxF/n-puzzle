#ifndef	HAMMING_HPP
# define HAMMING_HPP

# include "IHeuristic.hpp"

# include <string>
# include <vector>

class Hamming : public IHeuristic{

private:
	std::string				_name;

public:
	Hamming();
	virtual ~Hamming();

	virtual int					calculate(std::vector<int> const &map, Node const &goal) const;
	virtual std::string const	getName() const;

};

#endif
