NAME = fractol

CC = cc

CCFLAG = -Wall -Wextra -Werror -O2

MLX_DIR	= ./MLX42
MLX_LIB	= $(MLX_DIR)/build/libmlx42.a
HEADERS	= -I. -I$(MLX_DIR)/include
LIBS	= $(MLX_LIB) -lglfw -L"/opt/homebrew/lib" -framework Cocoa -framework OpenGL -framework IOKit

SRC = init.c  main.c  math.c  utlis.c render.c render2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAG) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)

%.o:%.c Makefile fractol.h
	@printf "\033[1;92mCompiled 👌🏽%s\033[0m\n" $@
	@$(CC) $(CCFLAG) -c $< -o $@
clean:
	@printf "\033[1;31mRemoved $(NAME) 💣\033[0m\n"
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)
re: fclean all 

.PHONY: clean fclean all re