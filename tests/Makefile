# **************************************************************************** #
#                          Minishell Unity Testing
# **************************************************************************** #

# i.e. make tests
# i.e. make

SRCS 	= $(shell find . -type f -iname "*.c"| cut -c 3-)
NAME	= $(SRCS:.c=)
OBJS	= $(NAME)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all: header $(OBJS) test

$(OBJS): %: %.c
	@$(CHK_ERR)
	@$(CC) $(CFLAGS) $< -o $@.out; ./$@.out > $@.log 2>&1   \
		&& (echo "$(wht)$(ck)$@	$(grn)[OK]$(rst)")          \
		|| (echo "$(wht)$(ck)$@	$(red)[KO]$(rst)" && ls>errl)
	@rm $@.out

header:
	@echo && echo "$(ora) Minishell Unity Testing$(rst)" && echo

test:
	@echo && echo "$(ora) Log Files $(rst)" && echo
	@for file in *.log; \
		do echo "$(pnk)$$file:$(rst)" \
		&& cat $$file && echo; \
		done
	@mkdir -p logs && mv *.log logs/
	@echo && if [ -f "errl" ]; \
		then rm errl; echo "$(red)\c"; false; \
		else echo "$(grn)make: *** [$@] SUCCESS! $(rst)"; fi

tests: all

.PHONY: test, tests, header

CHK_ERR =	if [ -f "errl" ]; then rm errl; fi

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
clr:=$s2K
lup:=$s1A
bld:=$s1m

spin[0]="⠁"
spin[1]="⠃"
spin[2]="⠇"
spin[3]="⠧"
spin[4]="⠷"
spin[5]="⠿"
spin[6]="⠷"
spin[7]="⠧"
spin[8]="⠇"
spin[9]="⠃"

# **************************************************************************** #
