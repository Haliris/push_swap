# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteissie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 11:52:05 by jteissie          #+#    #+#              #
#    Updated: 2024/06/25 16:27:11 by jteissie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Wall -Werror -Wextra

NAME = push_swap
BONUS_NAME = checker

LIBFT = ./libft/

INCLUDE =	-I ./include/ \
			-I ./libft/

BONUS_INCLUDE = -I ./bonus/

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
				utils.c \
				list_initialization.c \
				initialization_utils.c \
				atol_utils.c \
				check_utils.c \
				push_instructions.c \
				reverse_rotate_instructions.c \
				rotate_instructions.c \
				swap_instructions.c \

vpath %.c src src/find_cost src/find_cost/parse_stacks src/instructions bonus

OBJ_DIR = obj/

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES)) 

BONUS_OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(BONUS_FILES)) 

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(sort $(dir $(SRC_FILES))))

$(OBJ_FILES): $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< $(INCLUDE) -o $@

$(BONUS_OBJ_FILES): $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< $(INCLUDE) $(BONUS_INCLUDE) -o $@

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

.PHONY : all clean fclean re
