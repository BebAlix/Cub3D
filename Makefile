GREEN = /bin/echo -e "\x1b[1;3;32m$1\x1b[0m"
SRC = 	srcs/raycasting.c srcs/get_vars_raycasting.c srcs/bonus/bonus_mouse.c srcs/main.c srcs/init_vars.c srcs/close_win.c srcs/parsing.c srcs/get_file_content.c srcs/check_errors.c srcs/background_color.c srcs/free.c srcs/play.c srcs/display_map.c srcs/map_error.c 


OBJ = $(SRC:.c=.o)
CC = clang -g
CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a
INC = -I inc
NAME = cub3D

all:		$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft
	make -s -C ./mlx_linux
	$(CC) $(OBJ) $(LIB) $(INC) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(call GREEN,"Compilation success 😁")

clean:
		make clean -C ./libft
		rm -f $(OBJ) $(OBJ_BONUS)
		$(call GREEN,"The .o cleaned up !")

fclean:		clean
		make fclean -C ./libft
		make clean -s -C ./mlx_linux
		rm -f $(NAME)
		$(call GREEN,"The rest too !")

re:		fclean all

.SILENT:
.PHONY:		all clean fclean re
