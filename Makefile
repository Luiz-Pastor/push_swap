##############################################################################
NAME=push_swap
##############################################################################
CC := cc
FLAGS := -Wall -Werror -Wextra -g3
##############################################################################
LIB_FOLDER=lib
LIBFT_FOLDER=libft
##############################################################################
SRC=	main.c	\
		t_stack.c	\
		instructions_a.c \
		instructions_b.c \
		order.c

OBJ=$(SRC:%.c=%.o)
##############################################################################

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Llibft/ -lft


%.o: src/%.c
	$(CC) $(FLAGS) -c $<

libft:
	@echo "> Compiling \'libft\'\n"
	@make -C $(LIBFT_FOLDER)
	@cp $(LIBFT_FOLDER)/libft.a $(LIB_FOLDER)

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_FOLDER) fclean
	@rm -rf lib/libft.a

re: fclean $(NAME)

.PHONY: libft