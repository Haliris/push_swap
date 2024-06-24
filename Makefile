# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteissie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 11:52:05 by jteissie          #+#    #+#              #
#    Updated: 2024/06/24 18:08:48 by jteissie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Wall -Werror -Wextra

NAME = push_swap

LIBFT = ./libft/

INCLUDE =	-I ./include/ \
			-I ./libft/

SRC_FILES = main.c \
			move.c \
			utils.c \
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

vpath %.c src src/find_cost src/find_cost/parse_stacks src/instructions 

OBJ_DIR = obj/

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES)) 

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(sort $(dir $(SRC_FILES))))

$(OBJ_FILES): $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< $(INCLUDE) -o $@

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT) all
	$(CC) $(CCFLAGS) $(OBJ_FILES) -L./$(LIBFT) -lft -o $(NAME)

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(LIBFT)libft.a
	rm -f $(NAME)

re : fclean clean all

.PHONY : all clean fclean re
