# **************************************************************************** #
#    SETTINGS                                                                  #
# **************************************************************************** #

NAME		= 	minishell

SRCD		=	srcs
INCD		=	inc
TSTD		=	tests

# **************************************************************************** #
#    INCLUDES                                                                  #
# **************************************************************************** #

INC			=	-I ./libft/ -I ./libft/ft_printf/ -I ./inc/

# **************************************************************************** #
#    SOURCES AND OBJECTS                                                       #
# **************************************************************************** #

SRCS		=	srcs/signals/setup_signals.c \
				srcs/signals/int_handler.c \
				srcs/signals/default_signals.c \
				srcs/data_types/t_token.c \
				srcs/data_types/ft_strclear.c \
				srcs/data_types/t_sentence.c \
				srcs/data_types/ft_stradd_front.c \
				srcs/data_types/ft_strsetlast.c \
				srcs/data_types/ft_strdelone.c \
				srcs/data_types/ft_strnew.c \
				srcs/data_types/free_tab.c \
				srcs/data_types/ft_strtotallen.c \
				srcs/data_types/ft_stradd_back.c \
				srcs/data_types/env_unlink.c \
				srcs/data_types/ft_lst_to_str.c \
				srcs/data_types/protect_malloc.c \
				srcs/data_types/t_env.c \
				srcs/data_types/ft_strsize.c \
				srcs/redirects/counting_redirects.c \
				srcs/redirects/open_reds.c \
				srcs/redirects/heredoc.c \
				srcs/env/get_env.c \
				srcs/env/check_varname.c \
				srcs/env/get_global.c \
				srcs/env/swap_ptr.c \
				srcs/env/get_entry.c \
				srcs/env/expand_sentence.c \
				srcs/env/get_value.c \
				srcs/env/stash_string.c \
				srcs/env/scan_sentence.c \
				srcs/env/expand_hdoc.c \
				srcs/env/walk_hdoc.c \
				srcs/env/which_quotes.c \
				srcs/pipes/clear_pipe.c \
				srcs/pipes/counting_pipes.c \
				srcs/pipes/open_pipe.c \
				srcs/parser/isquotes.c \
				srcs/parser/lexer.c \
				srcs/parser/scan_line.c \
				srcs/parser/isdelim.c \
				srcs/parser/has_hdoc.c \
				srcs/parser/which_delim.c \
				srcs/sentence/quotes_removed.c \
				srcs/sentence/clean_reds_sentences.c \
				srcs/sentence/tkn_to_sentence.c \
				srcs/sentence/remove_quotes.c \
				srcs/sentence/quote_size.c \
				srcs/sentence/while_no_quotes.c \
				srcs/sentence/no_quote_size.c \
				srcs/sentence/create_sentences.c \
				srcs/sentence/new_index.c \
				srcs/prompt/open_pipe_reds.c \
				srcs/prompt/free_shell.c \
				srcs/prompt/readline_gets.c \
				srcs/prompt/main.c \
				srcs/prompt/ft_strlen_buf.c \
				srcs/prompt/launch_prog.c \
				srcs/prompt/print_executor_error.c \
				srcs/prompt/executor.c \
				srcs/prompt/init_shell.c \
				srcs/prompt/fill_shell.c \
				srcs/prompt/only_spaces.c \
				srcs/prompt/close_fds.c \
				srcs/builtins/check_unset.c \
				srcs/builtins/export.c \
				srcs/builtins/cd.c \
				srcs/builtins/isbuiltin.c \
				srcs/builtins/echo.c \
				srcs/builtins/pwd.c \
				srcs/builtins/export_error.c \
				srcs/builtins/print_export.c \
				srcs/builtins/unset.c \
				srcs/builtins/exit.c \
				srcs/builtins/check_export.c \
				srcs/builtins/env.c \
				srcs/builtins/call_builtin.c \
				srcs/builtins/compare_key.c \
				srcs/exec/path_to_lst.c \
				srcs/exec/env_to_array.c \
				srcs/exec/prefix_slash.c \
				srcs/exec/args_size.c \
				srcs/exec/exec_command.c \
				srcs/exec/print_execve_error.c \
				srcs/exec/call_execve.c

OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
#    LIBFT                                                                     #
# **************************************************************************** #

LFT			=	libft

CLFT		=	$(MFLAG) $(LFT)

LIBFT		= 	$(LFT)/$(LFT).a

# **************************************************************************** #
#    COMPILER AND FLAGS                                                        #
# **************************************************************************** #

CC			=	cc

RM			= 	rm -f

CFLAGS		=	-Wall -Wextra -Werror

RLFLAG		= 	-lreadline

MFLAG		=	-C

# **************************************************************************** #
#    READLINE SUPPORT                                                          #
# **************************************************************************** #

RL			=	readline

detected_OS	=	$(shell uname -s)
RL_TEST		=	if [ -z "$(RL_INC)" ]; then $(RL_MSG) && false; else true ; fi
NL			=	2>/dev/null
TL			=	-type d -name

INC_RL_MAC  =	-I $(RL_INC)
LIB_RL_MAC  =	-L $(RL_LIB)

ifeq ($(detected_OS), Linux)
 RL_PATH	+=	/usr/local /usr
 RL_INC 	=	$(shell find $(RL_PATH) $(TL) $(RL) | grep "include"| head -1)
 RLFLAGS	=	$(CFLAGS) $(INC)
 CO_LINE	=	$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)
else
 RL_PATH	+=	~/.brew /opt /usr/local
 RL_INC 	=	$(shell find $(RL_PATH) $(TL) include $(NL) |grep $(RL)|head -1)
 RL_LIB 	=	$(shell find $(RL_PATH) $(TL) lib $(NL) |grep $(RL)|head -1)
 RLFLAGS	=	$(CFLAGS) $(INC_RL_MAC) $(LIB_RL_MAC) $(INC)
 CO_LINE	=	$(CC) $(CFLAGS) $(INC) $(INC_RL_MAC) -c $< -o $(<:.c=.o)
endif

# **************************************************************************** #
#    Mandatory rules                                                           #
# **************************************************************************** #

.c.o:
			$(RL_TEST)
			${AT} $(CO_LINE) ${BLK}

all:		$(NAME)

$(LIBFT):
			${AT} $(MAKE) $(CLFT) ${BLK}
			${COMPILE}


$(NAME):	$(LIBFT) $(OBJS)
			${AT} $(CC) $(OBJS) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o $(NAME) ${BLK}
			${COMPILE}
clean:
			${AT} $(RM) $(OBJS) ${BLK}
			${AT} $(MAKE) $@ $(CLFT) ${BLK}
			$(RM_OBJS)

fclean:		clean
			${AT} $(RM) $(NAME) ${BLK}
			${AT} $(MAKE) $@ $(CLFT) ${BLK}
			$(RM_LIBS)

re:			fclean all


.PHONY:		all clean fclean re

# **************************************************************************** #
#                           Norminette
# **************************************************************************** #

.PHONY: norm
norm:
	${AT} echo "$(pnk)\c"; \
	norminette ${SRCS} ${INCD} | grep "Error" || \
	echo "$(grn)$(ok)	Norminette		OK!" ${BLK}

# **************************************************************************** #
#                           Tests
# **************************************************************************** #

.PHONY: tests
tests:
	if [ -f $(TSTD)/Makefile ]; then \
		$(MAKE) $@ $(MFLAG) $(TSTD); \
	else \
		echo "$(wht) Testing environment is not set \c"; \
		echo "$(ora)($(TSTD)/)$(rst)"; \
		false; \
	fi

# **************************************************************************** #
#                           Helper
# **************************************************************************** #

.PHONY: help
help:
	@$(PRT) "$(wht) make \c"
	@$(PRT) "$(wht) [all | clean | fclean | re | tests |\c"
	@$(PRT) "$(pnk) norm$(rst)]\c"
	@$(PRT) "$(cya) [VERBOSE=0..4]"
	@$(PRT) "$(wht) "
	@$(PRT) "$(cya) Verbose levels"
	@$(PRT) "$(wht) # 0: Make will be totaly silenced"
	@$(PRT) "$(grn) # 1: Make will print echos"
	@$(PRT) "$(yel) # 2: Make will not print target commands"
	@$(PRT) "$(ora) # 3: Make will print each command"
	@$(PRT) "$(red) # 4: Make will print all debug info $(rst)"

# **************************************************************************** #
#                          Verbose Check
# **************************************************************************** #

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print only
# echoes like if VERBOSE was set to 1.

VERBOSE		:= 1

ifeq (${VERBOSE}, 0)
	MAKEFLAGS += --silent
	BLK := >/dev/null
else ifeq (${VERBOSE}, 1)
	MAKEFLAGS += --silent
	AT := @
else ifeq (${VERBOSE}, 2)
	AT := @
else ifeq (${VERBOSE}, 4)
	MAKEFLAGS += --debug=v
endif

# **************************************************************************** #
#                           Visuals and Messages
# **************************************************************************** #

ok:=✓
ko:=✗
ck:=・

s:=\033[0
red:=$s31m
grn:=$s32m
yel:=$s33m
blu:=$s34m
pnk:=$s35m
cya:=$s36m
wht:=$s37m
rst:=$s00m
ora:=$s38;2;255;153;0m

PRT := echo
_OK := $(grn)$(ok)	Compiled		$(rst)
_CK := $(ora)$(ck)	Creating		$(rst)
_KO := $(red)$(ko)	Removing		$(rst)

COMPILE = ${AT} ${PRT} "${_OK}${grn}${@F}${rst}" ${BLK}
RM_OBJS = ${AT} ${PRT} "$(_KO)$(red)objects$(rst)" ${BLK}
RM_LIBS = ${AT} ${PRT} "$(_KO)$(red)${LFT}.a$(rst)" ${BLK}
RL_MSG  = ${PRT} "$(ora)$(ck)	${RL}${wht} is not installed.${rst}"

# **************************************************************************** #
