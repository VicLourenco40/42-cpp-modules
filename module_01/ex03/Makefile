NAME = violence

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
