NAME=ex00
CXX=c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98
SRC= main.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all