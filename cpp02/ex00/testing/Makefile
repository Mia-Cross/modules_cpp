NAME = fixed

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
		../Fixed.class.cpp
INCLUDES =	-I ../Fixed.class.hpp
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
	$(CXX) $(CXXFLAGS) -o $(NAME) ${OBJS}
	@echo Compiled $(NAME) successfully !

$(OBJDIR)/%.o : %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR) :
	@mkdir -p .obj

clean :
	@rm -rf $(OBJDIR)
	@rm -f *.o

fclean : clean
	@rm -f $(NAME)

re : fclean opti
