
NAME		=	cub3d
CC			=	gcc
FLAGS		=	# -Wall -Wextra -Werror
MLXFLAGS	=	-lmlx_Linux -lXext -lX11
RM			=	rm -fr
OBJECT_DIR	=	./objects/
MAKE_DIR	=	mkdir -p
INCLUDES	=	./includes
PATH_LIBVEC	=	./vectors
LIBFT = libft/libft.a
LIBFT_DIR = ./libft
SRC_FILES =	main.c \
			init.c \
			run.c \
			player_movement.c \
			vectors.c \
			draw.c \
			raycasting.c \
			hooks.c \
			render.c

SRC_DIR	=	./src/
SRC		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJECTS = $(patsubst $(SRC_DIR)%.c, $(OBJECT_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
		@make --no-print-directory -C $(PATH_LIBVEC)
		$(CC) $(FLAGS) -I $(INCLUDES) $(OBJECTS) $(LIBFT) -o $(NAME) $(MLXFLAGS) -lm -L$(PATH_LIBVEC) -lvec

$(OBJECT_DIR)%.o:	$(SRC_DIR)%.c
		$(MAKE_DIR) $(OBJECT_DIR)
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJECT_DIR)
	$(MAKE) -C $(PATH_LIBVEC) clean
	$(MAKE) fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make -C $(PATH_LIBVEC) fclean

re: fclean all

.PHONY: all clean fclean re
