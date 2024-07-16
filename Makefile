# -----------------------------------Makefile------------------------------------
NAME	= so_long.a

# -----------------------------------Sources-------------------------------------

HEADER	= so_long.h \
		/libft/includes/ft_printf.h\
		/libft/includes/libft.h\
		/libft/includes/get_next_line.h

SO_LONG_SRCS 	= main.c  \
				flood_fill.c\
				map_check.c



SO_LONG_SRC	= ${SO_LONG_SRCS}

ALL_SRC		= ${SO_LONG_SRC} 

OBJS	= ${ALL_SRC:.c=.o}

# -----------------------------------Compilation------------------------------------

FT_FOLDER = ./libft

FT = ${FT_FOLDER}/libft.a

CC		= gcc -g -fsanitize=address 

FLAGS	= -Wall -Wextra -Werror

LIB		= ar -rc

RM		= rm -f

MAKE_FT = make -s -C ${FT_FOLDER}

# -----------------------------------Libraries--------------------------------------

INCLUDES = -I ./includes

# -----------------------------------Rules------------------------------------------

all: ${NAME}

${NAME}: ${FT} ${OBJS}
		${LIB} ${NAME} ${OBJS}

${FT}: 
		${MAKE_FT}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c ${INCLUDES} $< -o $@

re: fclean all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
		${MAKE_FT} fclean

# -----------------------------------.phony--------------------------------------

.PHONY: all clean fclean re