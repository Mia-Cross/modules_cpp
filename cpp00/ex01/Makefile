NAME = annuaire

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = annuaire.cpp \
	Contact.class.cpp
INCLUDES =	-I Contact.class.hpp
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
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR) :
	@mkdir -p .obj

clean :
	@rm -rf $(OBJDIR)

fclean : clean
	@rm -f $(NAME)

re : fclean opti