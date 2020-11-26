NAME = megaphone

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp
OBJS =	$(SRCS:.cpp=.o)
DPDCS =	$(OBJS:.o=.d)

-include $(DPDCS)

all :
	@make $(NAME)

$(NAME) : $(OBJS)
	@printf "[$(NAME)] "
	$(CC) $(FLAGS) -o $(NAME) ${OBJS}
	@echo Compiled $(NAME) successfully !

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all