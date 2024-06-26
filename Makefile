# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 11:52:05 by jteissie          #+#    #+#              #
#    Updated: 2024/06/26 11:37:02 by jteissie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Wall -Werror -Wextra

NAME = push_swap
BONUS_NAME = checker

LIBFT = ./libft/

INCLUDE =	-I ./include/ \
			-I ./libft/

SRC_FILES = main.c \
			move.c \
			utils.c \
			atol_utils.c \
			check_utils.c \
			list_initialization.c \
			initialization_utils.c \
			find_a_costs.c \
			find_b_costs.c \
			find_costs_utils.c \
			parse_a.c \
			parse_b.c \
			push_instructions.c \
			reverse_rotate_instructions.c \
			rotate_instructions.c \
			swap_instructions.c \

BONUS_FILES =	main_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				utils_bonus.c \
				list_initialization_bonus.c \
				initialization_utils_bonus.c \
				atol_utils_bonus.c \
				check_utils_bonus.c \
				execute_instructions_bonus.c \
				push_instructions_bonus.c \
				reverse_rotate_instructions_bonus.c \
				rotate_instructions_bonus.c \
				swap_instructions_bonus.c \

vpath %.c src src/find_cost src/find_cost/parse_stacks src/instructions bonus bonus/instructions_bonus

OBJ_DIR = obj/

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))

BONUS_OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)bonus_%.o, $(BONUS_FILES))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(sort $(dir $(SRC_FILES))))

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< $(INCLUDE) -o $@

$(OBJ_DIR)bonus_%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< $(INCLUDE) -o $@

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT) all
	$(CC) $(CCFLAGS) $(OBJ_FILES) -L./$(LIBFT) -lft -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ_FILES)
	make -C $(LIBFT) all
	$(CC) $(CCFLAGS) $(BONUS_OBJ_FILES) -L./$(LIBFT) -lft -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(LIBFT)libft.a
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean clean all

.PHONY : all clean fclean re bonus
