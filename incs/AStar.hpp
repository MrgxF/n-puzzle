#ifndef	ASTAR_HPP
# define ASTAR_HPP

# include "Node.hpp"
# include "pq_custom.hpp"
# include "IHeuristic.hpp"
# include <list>
# include <map>
# include <iostream>

class AStar{

private:
	static int							_size;
	Node const							&_goal;
	IHeuristic const					&_h;
	Node								*_start;
	std::vector<Node*>					_finaleResult;

	std::map<std::vector<int>, Node*>	_set;
	pq_custom<Node>						_openList;

	void					pushOpenList(Node &node);
	void					pushFromCloseToOpen(Node &m);
	void					pushNewNodeToOpen(int const soFar, int const toReach,
														Node &map, Node *parent);

	void					getNeighbor(Node const &m, std::array<Node,4> &lst, int &nb);
	std::vector<Node*>		getPath(Node *);


public:
	AStar(Node *start, Node const &goal, IHeuristic const &h);
	virtual ~AStar();

	std::vector<Node*>		run();
	
	static int				getSize();
	int						getSetSize();

	static int				_totalStatesSelected;

	class NoSolution: public std::exception{
		public:
			NoSolution() throw();
			~NoSolution() throw();
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AStar const &c);

#endif

