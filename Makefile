# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 01:50:23 by alsaeed           #+#    #+#              #
#    Updated: 2024/03/25 22:25:20 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D
NAME_BONUS = cub3D_bonus

UNAME = $(shell uname)

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibs/libft/ -lft -lm
INCLUDES = -Iincludes/ -Ilibs/libft/includes

DSYM = cub3D.dSYM
DSYM_BONUS = cub3D_bonus.dSYM

ifeq ($(UNAME), Linux)
	CC = clang
	LDFLAGS += -Llibs/mlx_linux/ -lmlx_Linux -L/usr/lib -lXext -lX11 
	INCLUDES += -I/usr/include -Ilibs/mlx_linux/ -D__linux__
	MLX_DIR = libs/mlx_linux/
else ifeq ($(UNAME), Darwin)
	CC = cc
	LDFLAGS += -Llibs/mlx_macos/ -lmlx -framework OpenGL -framework AppKit -L/usr/lib
	INCLUDES += -Ilibs/mlx_macos/
	MLX_DIR = libs/mlx_macos/
endif

SRCD =	check.c \
		free.c \
		init_text.c \
		init_utils.c \
		verify.c \
		verify_utils.c \
		check_elements.c \
		scan_utils.c \
		map_utils.c \
		map_edit.c \
		get_file.c \
		element_utils.c \
		check_map_utils.c \
		final_parse.c

SRCX =	init.c \
		rect_map.c \
		raycast.c \
		keymap.c \
		wasd_move.c \
		wall_collision.c \
		draw_wall.c \
		draw_utils.c \
		close_game.c

OBJD_DIR = mandatory/src/parsing/objs
OBJD = $(SRCD:%.c=$(OBJD_DIR)/%.o)
OBJX_DIR = mandatory/src/execution/objs
OBJX = $(SRCX:%.c=$(OBJX_DIR)/%.o)

SRCD_BONUS =	check_bonus.c \
				free_bonus.c \
				init_text_bonus.c \
				init_utils_bonus.c \
				verify_bonus.c \
				verify_utils_bonus.c \
				check_elements_bonus.c \
				scan_utils_bonus.c \
				map_utils_bonus.c \
				map_edit_bonus.c \
				get_file_bonus.c \
				element_utils_bonus.c \
				check_map_utils_bonus.c \
				final_parse_bonus.c

SRCX_BONUS =	init_bonus.c \
				rect_map_bonus.c \
				raycast_bonus.c \
				keymap_bonus.c \
				wasd_move_bonus.c \
				wall_collision_bonus.c \
				draw_wall_bonus.c \
				draw_utils_bonus.c \
				close_game_bonus.c

OBJD_BONUS_DIR = bonus/src/parsing/objs
OBJD_BONUS = $(SRCD_BONUS:%.c=$(OBJD_BONUS_DIR)/%.o)
OBJX_BONUS_DIR = bonus/src/execution/objs
OBJX_BONUS = $(SRCX_BONUS:%.c=$(OBJX_BONUS_DIR)/%.o)

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MLX_DIR)libmlx.a

all: $(NAME_BONUS) $(NAME)

$(OBJD_DIR)%.o: mandatory/src/parsing%.c
	@mkdir -p $(OBJD_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
$(OBJX_DIR)%.o: mandatory/src/execution%.c
	@mkdir -p $(OBJX_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(MINILIBX) $(OBJD) $(OBJX) main.c
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJD) $(OBJX) main.c -o $(NAME) $(LDFLAGS)
	@echo "cub3D Compiled : \033[1;32mOK\033[0m"

bonus: $(NAME_BONUS)

$(OBJD_BONUS_DIR)%.o: bonus/src/parsing%.c
	@mkdir -p $(OBJD_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
$(OBJX_BONUS_DIR)%.o: bonus/src/execution%.c
	@mkdir -p $(OBJX_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME_BONUS): $(LIBFT) $(MINILIBX) $(OBJD_BONUS) $(OBJX_BONUS) main_bonus.c
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJD_BONUS) $(OBJX_BONUS) main_bonus.c -o $(NAME_BONUS) $(LDFLAGS)
	@echo "cub3D_bonus Compiled : \033[1;32mOK\033[0m"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MINILIBX):
	@make -sC $(MLX_DIR)
	@if [ $(UNAME) = Darwin ]; then \
		cp $(MLX_DIR)libmlx.a ./ ; \
	fi
	@echo "minilibx Compiled : \033[1;32mOK\033[0m"

norm:
	norminette mandatory bonus includes main.c main_bonus.c

clean:
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)
	
	@if [ -e $(OBJD_DIR) ]; then \
		rm -rf $(OBJD_DIR); \
		echo "cub3D-parsing Clean: \033[32mOK\033[0m"; \
	fi
	@if [ -e $(OBJX_DIR) ]; then \
		rm -rf $(OBJX_DIR); \
		echo "cub3D-execution Clean: \033[32mOK\033[0m"; \
	fi
	@if [ -e $(OBJD_BONUS_DIR) ]; then \
		rm -rf $(OBJD_BONUS_DIR); \
		echo "cub3D-bonus-parsing Clean: \033[32mOK\033[0m"; \
	fi
	@if [ -e $(OBJX_BONUS_DIR) ]; then \
		rm -rf $(OBJX_BONUS_DIR); \
		echo "cub3D-bonus-execution Clean: \033[32mOK\033[0m"; \
	fi
	@if [ -e $(DSYM) ]; then \
		rm -rf $(DSYM); \
		echo "cub3D-parsing Clean: \033[32mOK\033[0m"; \
	fi
	@if [ -e $(DSYM_BONUS) ]; then \
		rm -rf $(DSYM_BONUS); \
		echo "cub3D-parsing Clean: \033[32mOK\033[0m"; \
	fi
 
fclean: clean
	@make fclean -sC $(LIBFT_DIR)
	@if [ $(UNAME) = Darwin ]; then \
		rm -rf ./libmlx.a ; \
	fi
	@if [ -e $(NAME) ]; then \
		rm -f $(NAME); \
		echo "cub3D Full-Clean: \033[32mOK\033[0m"; \
	fi
	@if [ -e $(NAME_BONUS) ]; then \
		rm -f $(NAME_BONUS); \
		echo "cub3D-bonus Full-Clean: \033[32mOK\033[0m"; \
	fi

re: fclean all

.PHONY: all clean fclean re bonus