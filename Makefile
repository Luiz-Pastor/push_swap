##############################################################################
NAME=push_swap
##############################################################################
CC := cc
FLAGS := -Wall -Werror -Wextra -g3
##############################################################################
LIB_FOLDER=lib
LIBFT_FOLDER=libft
##############################################################################
SRC=	main.c

OBJ=$(SRC:%.c=%.o)
##############################################################################

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Llib/ -lft


%.o: src/%.c
	$(CC) $(FLAGS) -c $<

libft:
	@echo "> Compiling \'libft\'\n"
	@cd $(LIBFT_FOLDER) ; make
	@cp $(LIBFT_FOLDER)/libft.a $(LIB_FOLDER)

clean:
	@rm -rf $(OBJ)
	@cd $(LIBFT_FOLDER) ; make clean

fclean: clean
	@rm -rf $(NAME)
	@cd $(LIBFT_FOLDER) ; make fclean
	@rm -rf lib/libft.a

re: fclean $(NAME)

.PHONY: libft