
NAME		= UTester

# Config
# ****************************************************************************

SHELL		=	/bin/bash
CC			=	gcc
CFLAGS		=	-Wall -Wextra -MD $(INCLUDE)

RM			=	rm -rf

INCLUDE		=	-I utest -I ulog
OBJSDIR		=	obj

# Source files
# ****************************************************************************

TEST_DIR	=	tests
SRCS_FILES	=	main.c
TEST_SRCS	=	$(addprefix $(TEST_DIR)/, $(SRCS_FILES))

OBJS		=	$(addprefix $(OBJSDIR)/, $(SRCS_FILES:.c=.o))

$(OBJSDIR)/%.o:	$(TEST_DIR)/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

all:	$(NAME) run

$(NAME):	$(OBJS)
	@printf "$(_BLUE)\nTests compiled\n$(_END)"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS)
	@printf "$(_YELLOW)Launching tests...$(_END)\n"

run:
	@./$(NAME)

clean:
	@printf "$(_YELLOW)Removing object files...$(_END)\n"
	@$(RM) $(OBJSDIR)

fclean:
	@printf "$(_YELLOW)Removing object and binary file...$(_END)\n"
	@$(RM) $(OBJSDIR)
	@$(RM) $(NAME)

re:			fclean all

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

.PHONY: all clean fclean re debug run

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
