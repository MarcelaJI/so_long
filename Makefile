# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 08:58:14 by ingjimen          #+#    #+#              #
#    Updated: 2025/03/14 08:58:46 by ingjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
WIN_NAME= so_long.exe
CC = cc
HEADERS_DIR = /includes
SO_LONG_SRC_DIR = ./src
SO_LONG_SRC = so_long.c map_parse.c print_error.c free.c g_utils.c map_parse_2.c map_parse_3.c game.c asset_manager.c render.c render_2.c events.c dragon.c dragon_2.c

SRC_FILES = $(addprefix $(SO_LONG_SRC_DIR)/, $(SO_LONG_SRC))

# Agregar get_next_line a los archivos fuente
GNL_SRC_DIR = get_next_line
GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_FILES = $(addprefix $(GNL_SRC_DIR)/, $(GNL_SRC))

# Combinar todos los archivos fuente
ALL_SRC = $(SRC_FILES) $(GNL_FILES)

CFLAGS = -Wall -Werror -Wextra -IMLX42/include -I/usr/include/GLFW
CFLAGS_LEAKS = -Wall -Werror -Wextra -g -IMLX42/include -I/usr/include/GLFW

# Generar los archivos objeto (.o)
OBJFILES = $(ALL_SRC:.c=.o)

MAKEFLAGS += --no-print-directory

libft_dir = Libft
libft = $(libft_dir)/libft.a

ft_printf_dir = ft_printf
ft_printf = $(ft_printf_dir)/libftprintf.a

# MLX42
MLX42_DIR = MLX42/build
LINUX_MLX42 = $(MLX42_DIR)/libmlx42.a
WIN_MLX42 = $(MLX42_DIR)/libmlx42.a
MLX42_FLAGS = -lglfw -pthread -lm -ldl

# Colors
GREEN = \033[0;32m
RED = \033[1;31m
BLUE_UNDER = \033[1;34m
YELLOW = \033[0;33m
CYAN = \033[1;36m
MAGENTA = \033[0;35m
WHITE = \033[1;37m
WHITE_RED_BG = \033[0;41;37m
YELLOW_UNDER = \033[1;4;33m
NC = \033[0m

LINUX_MLX42_TARGET = linux_mlx
WIN_MLX42_TARGET = win_mlx

# Rules
all: $(libft) $(ft_printf) $(LINUX_MLX42_TARGET) $(OBJFILES) $(NAME)

$(NAME): $(OBJFILES) $(libft) $(ft_printf) $(LINUX_MLX42_TARGET)
	@echo "$(BLUE_UNDER)Compiling $(NAME)$(NC)"
	@$(CC) $(CFLAGS) $(OBJFILES) $(libft) $(ft_printf) $(LINUX_MLX42) $(MLX42_FLAGS) -o $(NAME)

# Compilar los archivos .o de get_next_line correctamente
get_next_line/%.o: get_next_line/%.c get_next_line/get_next_line.h
	@echo "$(BLUE_UNDER)Compiling get_next_line: $<$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(libft):
	@$(MAKE) -C $(libft_dir) all

$(ft_printf):
	@$(MAKE) -C $(ft_printf_dir) all

clean:
	@echo "$(BLUE_UNDER)Removing .o files in all directories$(NC)"
	@$(MAKE) -C $(libft_dir) clean
	@$(MAKE) -C $(ft_printf_dir) clean
	@rm -rf $(OBJFILES)

fclean: clean
	@echo "$(BLUE_UNDER)Removing .a files and executables$(NC)"
	@$(MAKE) -C $(libft_dir) fclean
	@$(MAKE) -C $(ft_printf_dir) fclean
	@rm -rf $(NAME) $(WIN_NAME)

re: fclean all

# Ejecutar
exe: all
	@echo "$(BLUE_UNDER)Executing $(NAME)...$(NC)"
	@./$(NAME) "$(ARGS)"
	@echo "$(GREEN)Program executed"
	@echo "$(BLUE_UNDER)Removing $(NAME)...$(NC)"
	@rm -rf $(NAME)

# MLX42 en Linux
$(LINUX_MLX42_TARGET):
	@if [ ! -d "MLX42" ]; then \
		echo "$(BLUE_UNDER)Cloning MLX42 repository...$(NC)"; \
		git clone git@github.com:codam-coding-college/MLX42.git; \
	fi
	@mkdir -p $(MLX42_DIR)
	@if [ ! -f "MLX42/build/libmlx42.a" ]; then \
		echo "$(BLUE_UNDER)Building MLX42 library...$(NC)"; \
		cd MLX42 && cmake -B build && cmake --build build; \
	fi
	@if [ -d "MLX42/build" ]; then \
		echo "$(BLUE_UNDER)Accessing build directory and finalizing build...$(NC)"; \
		cd MLX42/build && make; \
	else \
		echo "Error: MLX42/build directory not found!"; \
		exit 1; \
	fi
	@rm -rf MLX42/.github MLX42/.git

# Windows (WSL)
win_all: $(libft) $(ft_printf) $(WIN_MLX42_TARGET) $(OBJFILES) $(WIN_NAME)

$(WIN_NAME): $(OBJFILES) $(libft) $(ft_printf) $(WIN_MLX42_TARGET)
	@echo "$(BLUE_UNDER)Compiling $(WIN_NAME)$(NC)"
	@$(CC) $(CFLAGS) $(OBJFILES) $(libft) $(ft_printf) $(WIN_MLX42) $(MLX42_FLAGS) -o $(WIN_NAME)

.PHONY: WIN_MLX42 LINUX_MLX42 all win_all re clean fclean exe

