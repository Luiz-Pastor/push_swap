##############################################################################
NAME=push_swap
CHECKER=checker
##############################################################################
CC := cc
FLAGS := -Wall -Werror -Wextra
##############################################################################
LIBFT_FOLDER=libft
LIBFT=$(LIBFT_FOLDER)/libft.a
##############################################################################
SRC=	main.c	\
		t_stack.c	\
		instructions_a.c \
		instructions_b.c \
		instructions_both.c \
		order.c \
		arguments.c \
		utils.c \
		algorithm.c
OBJ=$(SRC:%.c=%.o)

SRC_BONUS=	checker.c \
			t_stack.c	\
			instructions_a.c \
			instructions_b.c \
			instructions_both.c \
			order.c \
			arguments.c \
			utils.c \
			algorithm.c
OBJ_BONUS=$(SRC_BONUS:%.c=%.o)
##############################################################################

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Llibft/ -lft

bonus: $(CHECKER)

$(CHECKER): libft $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(CHECKER) -Llibft/ -lft

%.o: src/%.c
	$(CC) $(FLAGS) -c $<

libft:
	@make -C $(LIBFT_FOLDER) all


clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -rf $(NAME) $(CHECKER)
	@make -C $(LIBFT_FOLDER) fclean

re: fclean $(NAME)

.PHONY: libft

test: $(NAME)
	clear;
	@cp $(NAME) tester
	@cd tester; bash push_swap_test.sh