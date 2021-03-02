#ifndef NPUZZLE_HPP
# define NPUZZLE_HPP

# include <iostream>
# include <string>
# include <array>
# include <unistd.h>

# include "Puzzle.hpp"

int				usage(int ret, Puzzle *puzzle);
void			parse_arguments(int ac, char **av, Puzzle *puzzle);
std::string		choose_heuristic(void);

#endif
