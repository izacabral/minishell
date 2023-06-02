INC			=	-I ../../libft/ -I ../../libft/ft_printf/ -I ../../inc/ -I ../

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g
#-fsanitize=address

LFT			=	libft

CLFT		=	$(MFLAG) $(LFT)

LIBFT		= 	../../$(LFT)/$(LFT).a

# **************************************************************************** #
#    ESPECIFICAR OS ARQUIVOS PARA UM DETERMINADO TESTE                         #
# **************************************************************************** #

SRCS_P_TOKEN	=	debug_print.c test_print_tokenization.c ../../srcs/parser/isdelim.c \
					../../srcs/parser/isquotes.c ../../srcs/parser/scan_line.c ../../srcs/parser/which_delim.c ../../srcs/data_types/t_token.c

OBJS_P_TOKEN	=	$(SRCS_P_TOKEN:.c=.o)

SRCS_EXECVE		=	test_execve.c ../../srcs/exec/call_execve.c ../../srcs/exec/path_to_lst.c ../../srcs/exec/prefix_slash.c ../../srcs/exec/launch_command.c ../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strdelone.c ../../srcs/data_types/ft_strsetlast.c ../../srcs/data_types/ft_strnew.c ../../srcs/data_types/free_tab.c

OBJS_EXECVE		=	$(SRCS_EXECVE:.c=.o)

SRCS_P_EXP_UNSET_ENV	= test_export_unset_env.c ../../srcs/builtins/export_error.c ../../srcs/builtins/check_export.c ../../srcs/builtins/check_unset.c ../../srcs/builtins/print_env.c \
							../../srcs/builtins/compare_key.c ../../srcs/builtins/export_builtin.c \
							../../srcs/builtins/print_export.c ../../srcs/builtins/unset_builtin.c ../../srcs/data_types/free_tab.c ../../srcs/env/get_env.c \
							../../srcs/data_types/t_env.c ../../srcs/prompt/init_shell.c\

OBJS_P_EXP_UNSET_ENV	=	$(SRCS_P_EXP_UNSET_ENV:.c=.o)

SRCS_EXPANDVAR	=	test_expandvars.c ../../srcs/env/expand_sentence.c ../../srcs/env/expandvars.c ../../srcs/env/get_value.c ../../srcs/env/scan_sentence.c ../../srcs/env/which_quotes.c ../../srcs/data_types/ft_strnew.c ../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strsize.c ../../srcs/data_types/ft_strsetlast.c ../../srcs/data_types/ft_lst_to_str.c ../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strdelone.c ../../srcs/data_types/ft_strtotallen.c

OBJS_EXPANDVAR	=	$(SRCS_EXPANDVAR:.c=.o)

SRCS_P_SENTENCE	=	test_print_t_sentence.c  ../../srcs/sentence/create_sentences.c ../../srcs/sentence/remove_quotes.c ../../srcs/sentence/tkn_to_sentence.c \
					../../srcs/data_types/t_sentence.c ../../srcs/sentence/new_index.c ../../srcs/sentence/no_quote_size.c ../../srcs/sentence/quotes_removed.c \
					../../srcs/sentence/while_no_quotes.c ../../srcs/sentence/quote_size.c\
					../../srcs/parser/isdelim.c \
					../../srcs/parser/isquotes.c ../../srcs/parser/scan_line.c ../../srcs/parser/which_delim.c \
					../../srcs/data_types/t_token.c ../../srcs/env/expand_sentence.c ../../srcs/env/expandvars.c \
					../../srcs/env/get_value.c ../../srcs/env/scan_sentence.c ../../srcs/env/which_quotes.c \
					../../srcs/data_types/ft_strnew.c ../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strsize.c \
					../../srcs/data_types/ft_strsetlast.c ../../srcs/data_types/ft_lst_to_str.c \
					../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strdelone.c ../../srcs/data_types/ft_strtotallen.c

OBJS_P_SENTENCE	=	$(SRCS_P_SENTENCE:.c=.o)

# **************************************************************************** #
#    READLINE SUPPORT                                                          #
# **************************************************************************** #

RL			=	readline
RLFLAG		= 	-lreadline

detected_OS	=	$(shell uname -s)
RL_TEST		=	if [ -z $(RL_INC) ]; then $(RL_MSG) && false; else true ; fi
NL			=	2>/dev/null

INC_RL_MAC  =	-I $(RL_INC)
LIB_RL_MAC  =	-L $(RL_LIB)

ifeq ($(detected_OS), Linux)
 RL_PATH	+=	/usr/local /usr
 RL_INC 	=	$(shell find $(RL_PATH) -type d -name $(RL) | grep "include")
 RLFLAGS	=	$(CFLAGS) $(INC)
 CO_LINE	=	$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)
else
 RL_PATH	+=	/opt ~/.brew /usr/local
 RL_INC 	=	$(shell find $(RL_PATH) -type d -name include $(NL) |grep $(RL))
 RL_LIB 	=	$(shell find $(RL_PATH) -type d -name lib $(NL) |grep $(RL))
 RLFLAGS	=	$(CFLAGS) $(INC_RL_MAC) $(LIB_RL_MAC) $(INC)
 CO_LINE	=	$(CC) $(CFLAGS) $(INC) $(INC_RL_MAC) -c $< -o $(<:.c=.o)
endif

# **************************************************************************** #
#              Rules                                                           #
# **************************************************************************** #

.c.o:
		$(CO_LINE)

all: printtoken printsentence printexpunsenv expandvar execve

printtoken: $(LIBFT) $(OBJS_P_TOKEN)
	$(CC) $(OBJS_P_TOKEN) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printtoken

execve: $(LIBFT) $(OBJS_EXECVE)
	cc hello_world.c -o hello_world
	$(CC) $(OBJS_EXECVE) $(LIBFT) -o $@

printexpunsenv: $(LIBFT) $(OBJS_P_EXP_UNSET_ENV)
	$(CC) $(OBJS_P_EXP_UNSET_ENV) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printexpunsenv

expandvar:	$(LIBFT) $(OBJS_EXPANDVAR)
	$(CC) $(CFLAGS) $(OBJS_EXPANDVAR) $(LIBFT) -o $@

printsentence: $(LIBFT) $(OBJS_P_SENTENCE)
	$(CC) $(OBJS_P_SENTENCE) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printsentence

clean:
		$(RM) $(OBJS_P_TOKEN) $(OBJS_P_SENTENCE) $(OBJS_P_EXP_UNSET_ENV) $(OBJS_EXPANDVAR) $(OBJS_EXECVE)

fclean: clean
		$(RM) printtoken printsentence printexpunsenv expandvar execve

re:			fclean all
