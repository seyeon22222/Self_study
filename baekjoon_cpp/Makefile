NAME = a.out
## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

## file
# HEADERS = PmergeMe.hpp
SRCS = 11003.cpp
OBJS = $(SRCS:.cpp=.o)

## compile
CXX=	c++ -fsanitize=address -g
#-fsanitize=address -g
CXXFLAGS = -std=c++17

.PHONY: clean, fclean, re, all

all: $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Link"
	$(CXX) -o $@ $(OBJS) 

$(OBJS): %.o: %.cpp $(HEADERS)
	@$(LOG) "Compile"
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@$(LOG) "clean"
	@rm -f $(OBJS) 

fclean: clean
	@$(LOG) "fclean"
	@rm -f $(NAME)

re:
	@$(LOG) "re"
	@make fclean
	@make all
