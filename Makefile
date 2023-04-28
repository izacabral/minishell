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

SRCS		=	srcs/data_types/cmd_tools.c \
				srcs/data_types/file_tools.c \
				srcs/data_types/free_tab.c \
				srcs/data_types/ft_stradd_back.c \
				srcs/data_types/ft_stradd_front.c \
				srcs/data_types/ft_strclear.c \
				srcs/data_types/ft_strdelone.c \
				srcs/data_types/ft_strnew.c \
				srcs/data_types/ft_strsetlast.c \
				srcs/data_types/ft_strsize.c \
				srcs/data_types/t_data_tools.c \
				srcs/parser/get_cmd.c \
				srcs/parser/parse_line.c \
				srcs/parser/debug_print.c \
				srcs/prompt/int_handler.c \
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

BIBRLMAC	=	-L ~/.brew/opt/readline/lib/

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



