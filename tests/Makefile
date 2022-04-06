
NAME		=	tester
LIBUNIT		=	libunit.a

# Config
# ****************************************************************************

SHELL 		=	/bin/bash
CC 			=	gcc

CFLAGS		=	-Wall -Wextra -MD $(INCLUDE)

INCLUDE		=	-I../framework/includes -I../libft -I includes

# Source files
# ****************************************************************************

SRCDIR		=	src

LIBUNIT_DIR	=	libunit
SRC_LIBUNIT	=	00_libunit_launcher.c 01_libunit_ok_test.c 02_libunit_ko_test.c 03_libunit_sigsegv_test.c		\
				04_libunit_sigbus_test.c 05_libunit_sigabort_test.c 06_libunit_sigfpe_test.c 					\
				07_libunit_sigpipe_test.c 08_libunit_sigill_test.c 09_libunit_timeout_test.c
TEST_LIBUNIT	=	$(addprefix $(LIBUNIT_DIR)/, $(SRC_LIBUNIT))

TEST_SRCS	=	$(addprefix $(SRCDIR)/, main.c)					\
				$(addprefix $(SRCDIR)/, $(TEST_LIBUNIT))

OBJDIR_TEST	=	objt
OBJSTEST	=	$(addprefix $(OBJDIR_TEST)/, $(notdir $(TEST_SRCS:.c=.o)))

$(OBJDIR_TEST)/%.o:	$(SRCDIR)/%.c | $(OBJDIR_TEST)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJDIR_TEST)/%.o:	$(SRCDIR)/*/%.c | $(OBJDIR_TEST)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

all: 		$(NAME)

$(NAME):	$(OBJSTEST)
	@$(CC) $(CFLAGS) $(OBJSTEST) ../$(LIBUNIT) -o $(NAME)

# Action
# ****************************************************************************

clean:
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@rm -rf $(OBJDIR_TEST)
	@rm -rf *.dSYM

fclean:		clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@rm -rf $(NAME)

re:		fclean all

$(OBJDIR_TEST):
	@mkdir -p $(OBJDIR_TEST)

.PHONY: all clean fclean re debug libft test

# Misc
# =====================

print-%:	; @echo $* = $($*)

# Colors
# ****************************************************************************

_GREY	= \033[30m
_RED	= \033[31m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

# ****************************************************************************
