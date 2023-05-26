INC			=	-I ../../libft/ -I ../../libft/ft_printf/ -I ../../inc/ -I ../

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

LFT			=	libft

CLFT		=	$(MFLAG) $(LFT)

LIBFT		= 	../../$(LFT)/$(LFT).a

# **************************************************************************** #
#    ESPECIFICAR OS ARQUIVOS PARA UM DETERMINADO TESTE                         #
# **************************************************************************** #

SRCS_P_TOKEN	=	debug_print.c test_print_tokenization.c ../../srcs/parser/isdelim.c ../../srcs/parser/isquotes.c ../../srcs/parser/scan_line.c ../../srcs/parser/which_delim.c ../../srcs/data_types/t_token.c

OBJS_P_TOKEN	=	$(SRCS_P_TOKEN:.c=.o)

SRCS_P_EXP_UNSET_ENV	= test_export_unset_env.c ../../srcs/builtins/export_error.c ../../srcs/builtins/check_export.c ../../srcs/builtins/check_unset.c ../../srcs/builtins/print_env.c \
							../../srcs/builtins/compare_key.c ../../srcs/builtins/export_builtin.c \
							../../srcs/builtins/print_export.c ../../srcs/builtins/unset_builtin.c ../../srcs/data_types/free_tab.c ../../srcs/env/get_env.c \
							../../srcs/data_types/t_env.c ../../srcs/prompt/init_shell.c\

OBJS_P_EXP_UNSET_ENV	=	$(SRCS_P_EXP_UNSET_ENV:.c=.o)

SRCS_EXPANDVAR	=	test_expandvars.c ../../srcs/env/expand_sentence.c ../../srcs/env/expandvars.c ../../srcs/env/get_value.c ../../srcs/env/scan_sentence.c ../../srcs/env/which_quotes.c ../../srcs/data_types/ft_strnew.c ../../srcs/data_types/ft_stradd_back.c ../../srcs/data_types/ft_strsize.c ../../srcs/data_types/ft_strsetlast.c ../../srcs/data_types/ft_lst_to_str.c ../../srcs/data_types/ft_strclear.c ../../srcs/data_types/ft_strdelone.c ../../srcs/data_types/ft_strtotallen.c

OBJS_EXPANDVAR	=	$(SRCS_EXPANDVAR:.c=.o)

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

all: printtoken printexpunsenv

printtoken: $(LIBFT) $(OBJS_P_TOKEN)
	$(CC) $(OBJS_P_TOKEN) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printtoken

printexpunsenv: $(LIBFT) $(OBJS_P_EXP_UNSET_ENV)
	$(CC) $(OBJS_P_EXP_UNSET_ENV) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printexpunsenv

expandvar:	$(LIBFT) $(OBJS_EXPANDVAR)
	$(CC) $(CFLAGS) $(OBJS_EXPANDVAR) $(LIBFT) -o $@

clean:
		$(RM) $(OBJS_P_TOKEN) $(OBJS_P_EXP_UNSET_ENV) $(OBJS_EXPANDVAR)

fclean: clean
		$(RM) printtoken printexpunsenv expandvar

re:			fclean all
