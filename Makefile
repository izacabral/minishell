# **************************************************************************** #
#    SETTINGS                                                                  #
# **************************************************************************** #

NAME		= 	minishell

WHICH_OS	= 	$(shell uname)

# **************************************************************************** #
#    INCLUDES                                                                  #
# **************************************************************************** #

INC	=	-I libft/ -I libft/ft_printf/ -I inc/

# **************************************************************************** #
#    SOURCES AND OBJECTS                                                       #
# **************************************************************************** #

SRCS		= 	srcs/parser/ft_isspace.c \
				srcs/parser/get_cmd.c \
				srcs/parser/parse_line.c \
				srcs/prompt/data_list.c \
				srcs/prompt/free_datacmd.c \
				srcs/prompt/int_handler.c \
				srcs/prompt/main.c \
				srcs/prompt/read_line.c \
				srsc/prompt/setup_signals.c \

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

LIBC		=	ar rc

RM			= 	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

INCRLMAC	=	-I/usr/local/opt/readline/include/

BIBRLMAC	=	-L/usr/local/opt/readline/lib/

RLFLAG		= 	-lreadline

ifeq ($(WHICH_OS), Linux)
 RLFLAGS	=	$(CFLAGS) $(INC)
else
 RLFLAGS	=	$(CFLAGS) $(INCRLMAC) $(BIBRLMAC) $(INC)
endif

# **************************************************************************** #
#    RULES                                                                     #
# **************************************************************************** #

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(LIBFT):
			$(MLIBFT)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(LIBC) $(RLFLAGS) $(OBJS) $(LIBFT) $(RLFLAG) -o $(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(LIBFT)
			$(RMLIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(FCLIBFT)

re:			fclean all

.PHONY:		all clean fclean re



