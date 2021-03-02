NAME		= n-puzzle

CC			= clang++

CFLAGS	= -Wall -Werror -Wextra
CVERSION= -std=c++11

CFLAGS	+= $(CVERSION)

SPEED =


OS			= $(shell uname -s)

PWD			= \"$(shell pwd)\"
ECHO		= echo
MKDIR		= mkdir

DEBUG		?= 0

SRCDIR   = srcs
OBJDIR   = objs/
INCLUDESDIR = incs


VPATH		= $(INCLUDESDIR) \
					$(SRCDIR) \
					$(SRCDIR)/templates \
					$(SRCDIR)/AStar \
					$(SRCDIR)/AStar/heuristic



SRCS			=	main.cpp \
						arguments_parsing.cpp \
						Node.cpp \
						Puzzle.cpp \
						Manhattan.cpp \
						Hamming.cpp \
						LinearConflicts.cpp \
						AStar.cpp

INCLUDES	= n-puzzle.hpp \
						Node.hpp \
						Puzzle.hpp \
						IHeuristic.hpp \
						Manhattan.hpp \
						Hamming.hpp \
						LinearConflicts.hpp \
						AStar.hpp \
						pq_custom.hpp \
						find_if_mix.hpp

OBJECTS			=	$(addprefix $(OBJDIR),  $(SRCS:.cpp=.o))
INC 				=	-I $(INCLUDESDIR) -I $(SRCDIR)/AStar -I $(SRCDIR) -I $(SRCDIR)/AStar/heuristic -I $(SRCDIR)/templates

EOC = \033[0m
ifeq ($(OS),Linux)
	CFLAGS += -DPATH=$(PWD) $(INC)
	OK_COLOR = \033[1;32m
	FLAGS_COLOR = \033[1;34m
	#COMP_COLOR =
else
	CFLAGS += -DPATH=$(PWD) $(INC)
	OK_COLOR = \x1b[32;01m
	#COMP_COLOR = \x1b[34;01m
	FLAGS_COLOR = \x1b[34;01m
#	COMP_COLOR =
endif

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

all:
	@$(ECHO) $(SRCS)
	@$(ECHO) $(OBJECTS)
	@$(ECHO) "$(FLAGS_COLOR)Compiling with flags $(CFLAGS) $(EOC)"
	@$(MAKE) $(NAME) $(SPEED)

$(NAME): $(OBJDIR) $(OBJECTS)
	@$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LFLAGS) \
		&& $(ECHO) "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(OBJDIR):
	@$(MKDIR) $@

$(OBJDIR)%.o:$(SRC_DIR)%.cpp $(INCLUDES)
	@$(CC) -c $< -o $@ $(CFLAGS)
	@$(ECHO) "${COMP_COLOR}$< ${EOC}"



clean:
	@$(RM) $(OBJECTS)
	@$(RM) -r $(OBJDIR) && $(ECHO) "${OK_COLOR}Successfully cleaned $(NAME) objects files ${EOC}"

fclean: clean
	@$(RM) $(NAME)  && $(ECHO) "${OK_COLOR}Successfully cleaned $(NAME) ${EOC}"

re: fclean all

rere:
	@$(RM) $(OBJECTS)
	@$(RM) -r $(OBJDIR)
	@$(RM) $(NAME)
	@$(MAKE) all

os:
	@$(ECHO) $(OS)

.PHONY: all clean fclean re debug
