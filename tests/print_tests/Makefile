INC			=	-I ../../libft/ -I ../../libft/ft_printf/ -I ../../inc/

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

LFT			=	libft

CLFT		=	$(MFLAG) $(LFT)

LIBFT		= 	../../$(LFT)/$(LFT).a

SRCS_P_TOKEN	=	debug_print.c test_print_tokenization.c ../../srcs/parser/isdelim.c ../../srcs/parser/isquotes.c ../../srcs/parser/scan_line.c ../../srcs/parser/which_delim.c ../../srcs/data_types/t_token.c

OBJS_P_TOKEN	=	$(SRCS_P_TOKEN:.c=.o)


# **************************************************************************** #
#    READLINE SUPPORT                                                          #
# **************************************************************************** #

CC			=	cc

RM			= 	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

INCRLMAC	=	-I ~/.brew/opt/readline/include/
#INCRLMAC	+=	-I /opt/homebrew/Cellar/readline/8.2.1/include/

BIBRLMAC	=	-L ~/.brew/opt/readline/lib/
#BIBRLMAC	+=	-I /opt/homebrew/Cellar/readline/8.2.1/lib/

RLFLAG		= 	-lreadline

ifeq ($(WHICH_OS), Linux)
 RLFLAGS	=	$(CFLAGS) $(INC)
 CO_LINE	=   $(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)
else
 RLFLAGS	=	$(CFLAGS) $(INCRLMAC) $(BIBRLMAC) $(INC)
 CO_LINE	=   $(CC) $(CFLAGS) $(INC) $(INCRLMAC) -c $< -o $(<:.c=.o)
endif

.c.o:
		$(CO_LINE)

all: printtoken

printtoken: $(LIBFT) $(OBJS_P_TOKEN)
	$(CC) $(OBJS_P_TOKEN) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o printtoken


clean:
		$(RM) $(OBJS_P_TOKEN)

fclean: clean
		$(RM) printtoken

re:			fclean all
