
NAME		= UTest

# Config
# ****************************************************************************

SHELL 		=	/bin/bash
CC 			=	gcc
CFLAGS		=	-Wall -Wextra -MD $(INCLUDE)

INCLUDE		=	-I utest

# Source files
# ****************************************************************************

TEST_DIR	= tests
TEST_SRCS	= main.c

$(OBJSDIR)/%.o:	$(TEST_SRCS)/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

all:		header $(NAME)

$(NAME):	$(OBJS)
	@printf "$(_BLUE)\nTests compiled\n$(_END)"
	@$(CC) -o $(BUILD)$(NAME) $(CFLAGS) $(TEST_SRCS)
	@printf "$(_YELLOW)Launching tests...$(_END)\n"
	@./$(NAME)
	@rm -f $(NAME)

clean:		header
	@printf "$(_YELLOW)Removing object files...$(_END)\n"
	@$(RM) $(OBJSDIR)

fclean:		header
	@printf "$(_YELLOW)Removing object and binary file...$(_END)\n"
	@$(RM) $(OBJSDIR)
	@$(RM) $(NAME)

re:			fclean all

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

.PHONY: all clean fclean re debug libft test run-test

# Misc
# =====================

print-%:	; @echo $* = $($*)

header:
	@printf "\n"
	@printf "$(_YELLOW)$(_END)\n"
	@printf "\n"

# Colors
# ****************************************************************************

_GREY		=	\033[30m
_RED		=	\033[31m
_GREEN		=	\033[32m
_YELLOW		=	\033[33m
_BLUE		=	\033[34m
_PURPLE		=	\033[35m
_CYAN		=	\033[36m
_WHITE		=	\033[37m
_END		=	\033[0m

# ****************************************************************************
