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
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm $(OBJS)

fclean : clean
	@rm $(NAME)

re :
	@make fclean
	@make