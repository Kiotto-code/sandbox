NAME = cub3d

GCC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDES = -Iinc
RM = rm -rf

SRC_PATH = src
OBJ_PATH = obj
LIB_PATH = libft
ANNOYING = .vscode

MAIN = main.c
SRC = cub3d.c
OBJ = ${addprefix ${OBJ_PATH}/, ${SRC:.c=.o}}

LIBFT = ${LIB_PATH}/libft.a
LIBFT_DIR = -L${LIB_PATH} -lft

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	@${GCC} ${CFLAGS} ${INCLUDES} ${MLXFLAGS} -o ${NAME} ${MAIN} ${OBJ} ${LIBFT_DIR}

${LIBFT}:
	@make re -C ${LIB_PATH}

${OBJ_PATH}/%.o: ${SRC_PATH}/%.c
	@mkdir -p ${@D}
	@${GCC} ${CFLAGS} ${INCLUDES} -c $< -o $@

test: cubclean all
	@./cub3d maps/map.cub

clean:
	@${RM} ${ANNOYING}
	@${RM} ${OBJ_PATH}
	@make clean -C ${LIB_PATH}

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIB_PATH}

cubclean:
	@${RM} ${NAME}
	@${RM} ${OBJ_PATH}

re: fclean all

.PHONY = all clean fclean re