NAME = convert

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
SRCS = 	Convert.cpp \
		main.cpp 

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
	$(CXX) $(CXXFLAGS) -c $< -o $@

tests :
	@echo ""
	@echo "NUMERIC VALUES"
	@echo ""
	./$(NAME) 42
	./$(NAME) 0
	./$(NAME) -1
	./$(NAME) 126.0
	./$(NAME) 42.0f
	./$(NAME) 2147483647
	./$(NAME) 2147483648
	./$(NAME) 0.00000001
	./$(NAME) -0.00000001
	@echo ""
	@echo "FROM CHAR OR STRING"
	@echo ""
	./$(NAME) Z
	./$(NAME) '&'
	./$(NAME) "s"
	./$(NAME) hello
	@echo ""
	@echo "INFINITE VALUES"
	@echo ""
	./$(NAME) inf
	./$(NAME) +inf
	./$(NAME) -inf
	./$(NAME) inff
	./$(NAME) +inff
	./$(NAME) -inff
	@echo ""
	@echo "NOT A NUMBER"
	@echo ""
	./$(NAME) nan
	./$(NAME) nanf

$(OBJDIR) :
	@mkdir -p .obj

clean :
	@rm -rf $(OBJDIR)
	@rm -f *.o
	@rm -f *.out

fclean : clean
	@rm -f $(NAME)

re : fclean opti
