# **************************************************************************** #
#    SETTINGS                                                                  #
# **************************************************************************** #

NAME		= 	minishell

# **************************************************************************** #
#    INCLUDES                                                                  #
# **************************************************************************** #

INC	=	-I ./libft/ -I ./libft/ft_printf/ -I ./inc/

# **************************************************************************** #
#    SOURCES AND OBJECTS                                                       #
# **************************************************************************** #

SRCS	=	$(shell find srcs ! -path srcs -type f | grep -E ".+\.c")
OBJS	=	$(SRCS:.c=.o)

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

RLFLAG		= 	-lreadline

# **************************************************************************** #
#    READLINE SUPPORT                                                          #
# **************************************************************************** #

detected_OS	=	$(shell uname -s)
RL_PATH     =	$(shell find $(HOMEBREW_CELLAR) -type d -name readline|head -1)
RL_INC      =	$(shell find $(RL_PATH) -type d -name include | head -1)
RL_LIB      =	$(shell find $(RL_PATH) -type d -name lib | head -1)

INC_RL_MAC  =	-I $(RL_INC)
LIB_RL_MAC  =	-L $(RL_LIB)

#detect_arch =	$(shell uname -m)
#ifeq ($(detect_arch), i386)
# INC_RLMAC	=	-I ~/.brew/opt/readline/include/
# LIB_RLMAC	=	-L ~/.brew/opt/readline/lib/
#else
# INCRLMAC	=	-I $(RL_INC)
# BIBRLMAC	=	-L $(RL_LIB)
#endif

ifeq ($(detected_OS), Linux)
 RLFLAGS	=	$(CFLAGS) $(INC)
 CO_LINE	=   $(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)
else
 RLFLAGS	=	$(CFLAGS) $(INC_RL_MAC) $(LIB_RL_MAC) $(INC)
 CO_LINE	=   $(CC) $(CFLAGS) $(INC) $(INC_RL_MAC) -c $< -o $(<:.c=.o)
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

list:
	@echo "*** SRC_ROOT: $(SRC_ROOT)"
	@echo "*** SRCS:  $(SRCS)"

fclean:		clean
			$(RM) $(NAME)
			$(FCLIBFT)

re:			fclean all


.PHONY:		all clean fclean re



