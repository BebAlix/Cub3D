GREEN = /bin/echo -e "\x1b[1;3;32m$1\x1b[0m"
SRC = 	srcs/mandatory/init_player.c \
		srcs/mandatory/raycasting.c \
		srcs/mandatory/get_vars_raycasting.c \
		srcs/mandatory/main.c \
		srcs/mandatory/init_vars.c \
		srcs/mandatory/close_win.c \
		srcs/mandatory/parsing/parsing.c \
		srcs/mandatory/parsing/parsing_utils.c \
		srcs/mandatory/parsing/check_parsing_infos.c \
		srcs/mandatory/parsing/get_file_content.c \
		srcs/mandatory/parsing/check_errors.c \
		srcs/mandatory/parsing/background_color.c \
		srcs/mandatory/parsing/map_error.c \
		srcs/mandatory/free.c \
		srcs/mandatory/play.c \
		srcs/mandatory/display_map.c

SRC_BONUS =	srcs/bonus/init_player_bonus.c \
			srcs/bonus/raycasting_bonus.c \
			srcs/bonus/get_vars_raycasting_bonus.c \
			srcs/bonus/mouse_bonus.c \
			srcs/bonus/print_map_bonus.c \
			srcs/bonus/main_bonus.c \
			srcs/bonus/init_vars_bonus.c \
			srcs/bonus/close_win_bonus.c \
			srcs/bonus/parsing/parsing_bonus.c \
			srcs/bonus/parsing/parsing_utils_bonus.c \
			srcs/bonus/parsing/check_parsing_infos_bonus.c \
			srcs/bonus/parsing/get_file_content_bonus.c \
			srcs/bonus/parsing/check_errors_bonus.c \
			srcs/bonus/parsing/background_color_bonus.c \
			srcs/bonus/parsing/map_error_bonus.c \
			srcs/bonus/free_bonus.c \
			srcs/bonus/play_bonus.c \
			srcs/bonus/display_map_bonus.c \
			srcs/bonus/change_map_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
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

bonus: $(OBJ_BONUS)
	make -C ./libft
	make -s -C ./mlx_linux
	$(CC) $(OBJ_BONUS) $(LIB) $(INC) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
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
