
NAME		=	cub3d
CC			=	gcc
FLAGS		=	# -Wall -Wextra -Werror
MLXFLAGS	=	-lmlx_Linux -lXext -lX11
RM			=	rm -f
INCLUDE		=	cub3d.h
PATH_LIBVEC	=	./vectors

SRC_FILES =	main.c \
			init.c \
			run.c


SRC =	$(SRC_FILES)

OBJECTS = $(SRC:.c=.o)

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
		make -C $(PATH_LIBVEC)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) $(MLXFLAGS) -lm -L$(PATH_LIBVEC) -lvec

clean:
	$(RM) $(OBJECTS)
	make -C $(PATH_LIBVEC) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PATH_LIBVEC) fclean

re: fclean all

.PHONY: all clean fclean re
