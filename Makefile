
UTEST		= utester
ULOG		= uloger

# Config
# ****************************************************************************

SHELL		=	/bin/bash
CC			=	gcc
CFLAGS		=	-Wall -Wextra -MD $(INCLUDE)

RM			=	rm -rf

INCLUDE		=	-I src
OBJSDIR		=	obj

# Source files
# ****************************************************************************

TEST_DIR	=	tests
UTEST_SRCS	=	tests/utest_main.c
ULOG_SRCS	=	tests/ulog_main.c

OBJS_UTEST	=	$(addprefix $(OBJSDIR)/, $(notdir $(UTEST_SRCS:.c=.o)))
OBJS_ULOG	=	$(addprefix $(OBJSDIR)/, $(notdir $(ULOG_SRCS:.c=.o)))

DEPENDS		=	$(OBJS_UTEST:.o=.d)	\
				$(OBJS_ULOG:.o=.d)

$(OBJSDIR)/%.o:	$(TEST_DIR)/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

all:	$(UTEST) $(ULOG) run

$(UTEST):	$(OBJS_UTEST) | $(OBJSDIR)
	@printf "$(_BLUE)\nTests compiled\n$(_END)"
	@$(CC) -o $(UTEST) $(CFLAGS) $(OBJS_UTEST)
	@printf "$(_YELLOW)Launching tests...$(_END)\n"

$(ULOG):	$(OBJS_ULOG) | $(OBJSDIR)
	@printf "$(_BLUE)\nTests compiled\n$(_END)"
	@$(CC) -o $(ULOG) $(CFLAGS) $(OBJS_ULOG)
	@printf "$(_YELLOW)Launching tests...$(_END)\n"

run: utest ulog

utest:	$(UTEST)
	@./$(UTEST)

ulog:	$(ULOG)
	@./$(ULOG)

clean:
	@printf "$(_YELLOW)Removing object files...$(_END)\n"
	@$(RM) $(OBJSDIR)

fclean:
	@printf "$(_YELLOW)Removing object and binary file...$(_END)\n"
	@$(RM) $(OBJSDIR)
	@$(RM) $(UTEST) $(ULOG)

re:			fclean all

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

.PHONY: all clean fclean re debug run

-include $(DEPENDS)

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
