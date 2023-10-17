##############################################################################
NAME=push_swap
##############################################################################
CC := cc
FLAGS := -Wall -Werror -Wextra
##############################################################################
LIB_FOLDER=lib
LIBFT_FOLDER=libft
LIBFT=$(LIBFT_FOLDER)/libft.a
##############################################################################
SRC=	main.c	\
		t_stack.c	\
		instructions_a.c \
		instructions_b.c \
		order.c \
		arguments.c

OBJ=$(SRC:%.c=%.o)
##############################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Llibft/ -lft


%.o: src/%.c
	$(CC) $(FLAGS) -c $<

$(LIBFT):
	@echo "> Compiling 'libft'\n"
	@make -C $(LIBFT_FOLDER)
	@cp $(LIBFT_FOLDER)/libft.a $(LIB_FOLDER)

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_FOLDER) fclean
	@rm -rf lib/libft.a

test: $(NAME)
	@cp $(NAME) tester
	@cd tester; bash push_swap_test.sh

re: fclean $(NAME)

.PHONY: libft