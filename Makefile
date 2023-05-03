# **************************************************************************** #
#    SETTINGS                                                                  #
# **************************************************************************** #

NAME		= 	minishell

WHICH_OS	= 	$(shell uname)

# **************************************************************************** #
#    INCLUDES                                                                  #
# **************************************************************************** #

INC	=	-I ./libft/ -I ./libft/ft_printf/ -I ./inc/

# **************************************************************************** #
#    SOURCES AND OBJECTS                                                       #
# **************************************************************************** #

SRCS		=	srcs/data_types/free_tab.c \
				srcs/data_types/t_token.c \
				srcs/parser/debug_print.c \
				srcs/parser/isdelim.c \
				srcs/parser/isquotes.c \
				srcs/parser/scan_line.c \
				srcs/parser/which_delim.c \
				srcs/prompt/int_handler.c \
				srcs/prompt/launch_prog.c \
				srcs/prompt/main.c \
				srcs/prompt/read_line.c \
				srcs/prompt/setup_signals.c \

OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
#    LIBFT                                                                     #
# **************************************************************************** #

LIBFT		= 	libft/libft.a

MLIBFT		=	make -C libft

RMLIBFT		=	make -C libft clean

FCLIBFT		=	make -C libft fclean

# **************************************************************************** #
#    COMPILER AND FLAGS                                                        #
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

# **************************************************************************** #
#    RULES                                                                     #
# **************************************************************************** #

.c.o:
			$(CO_LINE)

all:		$(NAME)

$(LIBFT):
			$(MLIBFT)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(OBJS) $(LIBFT) $(RLFLAGS) $(RLFLAG) -o $(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(LIBFT)
			$(RMLIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(FCLIBFT)

re:			fclean all

.PHONY:		all clean fclean re



