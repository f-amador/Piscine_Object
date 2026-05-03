NAME=ex00
CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRC=main.cpp Account.cpp Bank.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.Phony: all clean fclean re 