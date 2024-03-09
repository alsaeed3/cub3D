# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 12:19:50 by alsaeed           #+#    #+#              #
#    Updated: 2024/03/05 20:20:14 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------- colors ---------------------------------- #
GREEN := "\033[1;32m"
RED := "\033[1;3;31m"
BLUE := "\033[3;34m"
YELLOW := "\033[0;33m"
RESET := "\033[0m"

# --------------------------------- variables -------------------------------- #
NAME := cub3D
CFLAGS := -Wall -Wextra -Werror
UNAME := $(shell uname)
LIBRARY_FLAGS := -Llibft/ -lft -lm -lz -lmlx -Llibft/
INCLUDES := -Iincludes/ -Ilibft/includes

ifeq ($(UNAME), Linux)
	LIBRARY_FLAGS += -Lmlx_linux/ -lmlx_Linux -L/usr/lib -lXext -lX11
	INCLUDES += -Imlx_linux/ -I/usr/include -D__LINUX__
	MLX_DIR := mlx_linux/
else ifeq ($(UNAME), Darwin)
	LIBRARY_FLAGS += -Lmlx_macos/ -framework OpenGL -framework AppKit
	INCLUDES += -Imlx_macos/
	MLX_DIR := mlx_macos/
endif

SRCS_DIR = src
SRCS = 

OBJS_DIR = obj
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

LIBFT = libft/libft.a
MINILIBX = $(MLX_DIR)libmlx.a

MAP:= ./test_maps/split-map.cub

# ---------------------------------- targets --------------------------------- #
all : $(NAME)

run : all
	./$(NAME) $(MAP)

# --------------------------------- debugging -------------------------------- #

valgrind: CFLAGS += -DDEBUG -ggdb3
valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) $(MAP)

sanitize: CFLAGS += -fsanitize=address -ggdb3
sanitize: re
	./$(NAME) $(MAP)

debug: CFLAGS += -ggdb3
debug: re
	./$(NAME) $(MAP)

fast: CFLAGS += -O2
fast: re
	./$(NAME) $(MAP)


faster: CFLAGS += -O3
faster: re
	./$(NAME) $(MAP)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) main.c -o $(NAME) $(LIBRARY_FLAGS)
	@echo $(GREEN)"cub3D ready for play."$(RESET)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo $(BLUE)"Compiling $<."$(RESET)

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(LIBFT) :
	@echo $(YELLOW)"Creating $(LIBFT)"$(RESET)
	@make -sC libft
	@echo $(GREEN)"\nLibft is ready. ✅\n"$(RESET)

$(MINILIBX) :
	@echo $(YELLOW)"Creating $(MINILIBX)"$(RESET)
	@make -sC $(MLX_DIR)
	@if [ $(UNAME) = Darwin ]; then \
		cp $(MLX_DIR)libmlx.dylib ./ ; \
	fi
	@echo $(GREEN)"MLX Library is ready. ✅\n"$(RESET)

clean :
	@make clean -sC libft
	@make clean -sC $(MLX_DIR)
	@rm -rf $(OBJS_DIR)
	@echo $(RED)"\nRemoving object directory and files"$(RESET)

fclean : clean
	@rm -f $(NAME)
	@if [ $(UNAME) = Darwin ]; then \
		rm -f libmlx.dylib; \
	fi
	@make fclean -sC libft
	@echo $(RED)"Removing $(NAME), libft.a and libmlx.a\n"$(RESET)

re : fclean all

.PHONY = all clean fclean re

# # Colors
# GREEN := "\033[1;32m"
# RED := "\033[1;3;31m"
# BLUE := "\033[3;34m"
# YELLOW := "\033[0;33m"
# RESET := "\033[0m"

# # Compiler
# CC := cc
# CFLAGS := -Wall -Wextra -Werror

# LIB_FLAGS := -Llibft/ -lft -lm -lz -lmlx -Llibft/
# INC := -Iinc/ -Ilibft/inc

# # OS-Specification
# OS := $(shell uname)

# ifeq (${OS}, Darwin)
# 		MLX_DIR := mlx_macos
# 		MLX := mlx
# 		LIB_FLAGS += -L$(MLX_DIR)/ -framework OpenGL -framework AppKit
# 		INC += -I$(MLX_DIR)/ 
# else ifeq (${OS}, Linux)
# 		MLX_DIR := mlx_linux
# 		MLX := mlx_linux
# 		LIB_FLAGS += -L$(MLX_DIR)/ -l$(MLX_DIR) -L/usr/lib -lXext -lX11
# 		INC += -I$(MLX_DIR)/ -I/usr/include -D__LINUX__
# else
# 		echo $(RED)"unidentified OS"$(RESET)
# endif

# # cub3D
# NAME := cub3D

# # Sources
# SRCD := 
# SRCD_DIR := src/parsing
# SRCSD := $(addprefix $(SRCD_DIR)/, $(SRCD))

# SRCE := 
# SRCE_DIR := src/execution
# SRCSE := $(addprefix $(SRCE_DIR)/, $(SRCE))

# # Includes
# INC_DIR := inc
# INC_DATA := data.h
# INC_EXEC := exec.h
# INCLUDE := $(addprefix $(INC_DIR)/, )

# clean :
# 	@make clean -sC libft
# 	@make clean -sC $(MLX_DIR)
# 	@rm -rf $(OBJ)

# fclean : clean
# 	@rm -f $(NAME)
# 	@if [ $(UNAME) = Darwin ]; then \
# 		rm -rf libmlx.dylib; \
# 	fi
# 	@make fclean -sC libft
# 	@echo "cub3D full-clean: $(GREEN)OK\n$(RESET)" 

# re : fclean all

# .PHONY = all clean fclean re