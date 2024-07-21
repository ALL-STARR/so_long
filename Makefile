# -----------------------------------Makefile------------------------------------
NAME	= so_long

# -----------------------------------Sources-------------------------------------

HEADER	= so_long.h \
		/libft/includes/ft_printf.h\
		/libft/includes/libft.h\
		/libft/includes/get_next_line.h

SO_LONG_SRCS 	= main.c  \
				flood_fill.c\
				map_check.c\
				X_utils.c\
				movement.c



SO_LONG_SRC	= ${SO_LONG_SRCS}

ALL_SRC		= ${SO_LONG_SRC} 

OBJS	= ${ALL_SRC:.c=.o}

# -----------------------------------Compilation------------------------------------

FT_FOLDER = ./libft

MLX_FOLDER = ./mlx

MLX = ${MLX_FOLDER}/libmlx.a

FT = ${FT_FOLDER}/libft.a

CC		= gcc -g -fsanitize=address 

FLAGS	= -Wall -Wextra -Werror

LIB		= ar -rc

RM		= rm -f

MAKE_FT = make -s -C ${FT_FOLDER}

MAKE_MLX = make -s -C ${MLX_FOLDER}

MLX_FLAGS = -Lmlx -lmlx  -framework OpenGL -framework AppKit

# -----------------------------------Libraries--------------------------------------

INCLUDES = -I ./includes ./libft/includes -I ./mlx

# -----------------------------------Rules------------------------------------------

all: ${NAME}

$(NAME): $(OBJS) ${MLX} ${FT}
	$(CC) $(FLAGS) -o $(NAME)  $(OBJS) ${MLX} ${FT} $(MLX_FLAGS)

${FT}: 
		${MAKE_FT}

${MLX}:
		${MAKE_MLX}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c ${INCLUDES} $< -o $@

re: fclean all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
		${MAKE_FT} fclean
		${MAKE_MLX} fclean

# -----------------------------------.phony--------------------------------------

.PHONY: all clean fclean re