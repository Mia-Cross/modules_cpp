NAME = fixed

CC = clang++
FLAGS = -Wall -Wextra -Werror
SRCS = main.cpp \
		../Fixed.class.cpp
OBJDIR =	.obj
OBJS =	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DPDCS =	$(OBJS:.o=.d)

-include $(DPDCS)

opti:
	@make -j all

all :
	@make $(NAME)

$(NAME) : $(OBJS)
	@printf "[$(NAME)] "
	$(CC) $(FLAGS) -o $(NAME) ${OBJS}
	@echo Compiled $(NAME) successfully !

$(OBJDIR)/%.o : %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR) :
	@mkdir -p .obj

clean :
	@rm -r $(OBJDIR)

fclean : clean
	@rm $(NAME)

re :
	@make fclean
	@make opti