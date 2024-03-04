# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 12:19:50 by alsaeed           #+#    #+#              #
#    Updated: 2024/03/04 13:37:32 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

# OS-Specification
OS := $(shell uname)

ifeq (${OS}, Darwin)
		BUILD_DIR := minilibx_opengl_20191021
		MLX := mlx
		CFLAGS += -L$(BUILD_DIR) -I$(BUILD_DIR) -l$(MLX) -framework OpenGL -framework Appkit -Llibft -Ilibft/includes -lft -L/usr/lib -lm
else ifeq (${OS}, Linux)
		BUILD_DIR := minilibx_linux
		MLX := mlx_linux
		CFLAGS += -L$(BUILD_DIR) -I$(BUILD_DIR) -l$(MLX) -L/usr/lib -lXext -lX11 -lm -lz -Llibft -Ilibft/includes -lft
else
		$(unidentified OS)
endif

# cub3D
NAME := cub3D

# Sources
SRCD := 
SRCD_DIR := src/parsing
SRCSD := $(addprefix $(SRCD_DIR)/, $(SRCD))

SRCE := 
SRCE_DIR := src/execution
SRCSE := $(addprefix $(SRCE_DIR)/, $(SRCE))

# Includes
INC_DIR := inc
INC_DATA := data.h
INC_EXEC := exec.h
INCLUDE := $(addprefix $(INC_DIR)/, )
