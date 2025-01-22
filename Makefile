NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx/
MLX_LIB = $(MLX_DIR)libmlx_Linux.a
LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
PRINTF_DIR = printf/
PRINTF_LIB = $(PRINTF_DIR)libftprintf.a
SRC_DIR = srcs/
#SANITIZE = -fsanitize=address -g3

SRC = ${SRC_DIR}main.c ${SRC_DIR}init.c ${SRC_DIR}map_creator.c ${SRC_DIR}map_checker.c ${SRC_DIR}map_checker2.c ${SRC_DIR}utils.c ${SRC_DIR}display.c ${SRC_DIR}moving.c
OBJ = ${SRC:.c=.o}

MLX_FLAGS =  -L$(MLX_DIR) -lmlx_Linux -L/usr/lib/x11 -lXext -lX11 -lm

all: subsystems ${NAME}

%.o : %.c
	$(CC) $(FLAGS) -I$(MLX_DIR) -c -o $@ $<	

subsystems :
	@make -C $(MLX_DIR) all
	@make -C $(LIBFT_DIR) all
	@make -C $(PRINTF_DIR) all

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${MLX_FLAGS} ${OBJ} ${MLX_LIB} ${LIBFT_LIB} ${PRINTF_LIB} -o ${NAME} -g

clean:
	@make -C ${MLX_DIR} clean
	@make -C ${PRINTF_DIR} clean
	@make -C ${LIBFT_DIR} clean
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}
	@make -C ${MLX_DIR} clean
	@make -C ${PRINTF_DIR} fclean
	@make -C ${LIBFT_DIR} fclean
	
re : fclean all

.PHONY: all clean fclean re