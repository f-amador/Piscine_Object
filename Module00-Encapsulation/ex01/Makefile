NAME= graph
CXX= c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS= Vect2.cpp Graph.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(OBJS)

re: fclean all

.Phony= all clean fclean re