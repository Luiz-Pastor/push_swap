##############################################################################
NAME=push_swap
CHECKER=checker
##############################################################################
CC := cc
FLAGS := -Wall -Werror -Wextra
##############################################################################

SRC=	main.c	\
		t_stack.c	\
		instructions_a.c \
		instructions_b.c \
		instructions_both.c \
		order.c \
		arguments.c \
		utils.c \
		algorithm.c \
		best_move.c \
		check_cost.c \
		set_targets.c \
		ft_split.c \
		ft_strcmp.c \
		ft_strict_atoi.c \
		get_next_line.c \
		get_next_line_utils.c
OBJ=$(SRC:%.c=%.o)

SRC_BONUS=	checker.c \
			t_stack.c	\
			instructions_a.c \
			instructions_b.c \
			instructions_both.c \
			arguments.c \
			utils.c \
			ft_split.c \
			ft_strcmp.c \
			ft_strict_atoi.c \
			get_next_line.c \
			get_next_line_utils.c
OBJ_BONUS=$(SRC_BONUS:%.c=%.o)
##############################################################################

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(CHECKER)

%.o: src/%.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -rf $(NAME) $(CHECKER)

re: fclean $(NAME)

.PHONY: libft

test: $(NAME)
	clear;
	@cp $(NAME) tester
	@cd tester; bash push_swap_test.sh