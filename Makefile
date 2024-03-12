# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 12:19:50 by alsaeed           #+#    #+#              #
#    Updated: 2024/03/12 20:37:17 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------- variables -------------------------------- #

NAME :=	cub3D

UNAME := $(shell uname)

CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -Llibft/ -Ilibft/includes -lft -lm
INCLUDES := -Iincludes/ 



ifeq ($(UNAME), Linux)
    CC := cc
    LDFLAGS += -Lmlx_linux/ -Imlx_linux/ -lmlx_Linux -L/usr/lib -lXext -lX11
    INCLUDES += -I/usr/include -D__LINUX__
    MLX_DIR := mlx_linux/
else ifeq ($(UNAME), Darwin)
    CC := cc
    LDFLAGS += -Lmlx_macos/ -Imlx_macos/ -lmlx -framework OpenGL -framework AppKit -L/usr/lib
    MLX_DIR := mlx_macos/
endif

SRCD =	

SRCX =	

OBJD_DIR = src/parsing/objs/
OBJD = $(SRCD:%.c=$(OBJD_DIR)/%.o)
OBJX_DIR = src/execution/objs/
OBJX = $(SRCX:%.c=$(OBJX_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MLX_DIR)libmlx.a

all: $(NAME)

$(OBJD_DIR)%.o: parsing/%.c | $(OBJD_DIR)
	@mkdir -p $(OBJD_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
    
$(OBJX_DIR)%.o: execution/%.c | $(OBJX_DIR)
	@mkdir -p $(OBJX_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
    
$(NAME): $(LIBFT) $(MINILIBX) $(OBJS) $(OBJX) main.c
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJD) $(OBJX) main.c -o $(NAME) $(LDFLAGS)
    @echo "cub3D Compiled: \033[1;32mOK\033[0m"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MINILIBX):
	@echo $(YELLOW)"Creating $(MINILIBX)"$(RESET)
	@make -sC $(MLX_DIR)
	@if [ $(UNAME) = Darwin ]; then \
		cp $(MLX_DIR)libmlx.dylib ./ ; \
    fi
	@echo $(GREEN)"MLX Library is ready. ✅\n"$(RESET)

norm:
	norminette

clean:
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)
	@if [ -e $(OBJD_DIR) ]; then \
        rm -rf $(OBJD_DIR); \
        echo "minishell-parsing Clean: \033[32mOK\033[0m"; \
    fi
	@if [ -e $(OBJX_DIR) ]; then \
        rm -rf $(OBJX_DIR); \
        echo "minishell-execution Clean: \033[32mOK\033[0m"; \
    fi
 
fclean: clean
	@make fclean -sC $(LIBFT_DIR)
	@if [ $(UNAME) = Darwin ]; then \
        rm -rf ./libmlx.dylib ; \
    fi
	@if [ -e $(NAME) ]; then \
        rm -f $(NAME); \
        echo "minishell Full-Clean: \033[32mOK\033[0m"; \
    fi

re: fclean all

.PHONY: all clean fclean re
