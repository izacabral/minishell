# **************************************************************************** #
#    SETTINGS                                                                  #
# **************************************************************************** #

NAME		= 	minishell

# **************************************************************************** #
#    INCLUDES                                                                  #
# **************************************************************************** #

INC			=	-I ./libft/ -I ./libft/ft_printf/ -I ./inc/

# **************************************************************************** #
#    SOURCES AND OBJECTS                                                       #
# **************************************************************************** #

SRCS		=	$(shell find srcs ! -path srcs -type f | grep -E ".+\.c")
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

CFLAGS		=	-Wall -Wextra -Werror -g

RLFLAG		= 	-lreadline

MFLAG		=	-C

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
#    Mandatory rules                                                           #
# **************************************************************************** #

.c.o:
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
			$(DELOBJS)

fclean:		clean
			${AT} $(RM) $(NAME) ${BLK}
			${AT} $(MAKE) $@ $(CLFT) ${BLK}
			$(DELLIBS)

re:			fclean all


.PHONY:		all clean fclean re

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
DELOBJS = ${AT} ${PRT} "$(_KO)$(red)objects$(rst)" ${BLK}
DELLIBS = ${AT} ${PRT} "$(_KO)$(red)${LFT}.a$(rst)" ${BLK}

# **************************************************************************** #
