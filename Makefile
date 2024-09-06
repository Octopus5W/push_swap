# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 12:06:56 by hdelbecq          #+#    #+#              #
#    Updated: 2024/09/06 19:39:47 by hdelbecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/printf.a
INC_DIR = include
INC = -I$(INC_DIR) -I$(PRINTF_DIR)
SRC_DIR = sources
OBJ_DIR = obj
RM = rm -rf

SRCS = \
	algo.c\
	check_av.c\
	ft_itoa.c\
	ft_split.c\
	push_swap.c\
	push.c\
	reverse.c\
	rotate.c\
	swap.c\
	utils1.c\
	utils2.c\
	utils3.c

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(PRINTF): | $(PRINTF_DIR)
			$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF)
			$(CC) $(CFLAGS) -o $@ $(OBJ) $(PRINTF) $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
			$(RM) $(OBJ_DIR)
			$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(PRINTF_DIR)

re:        fclean all

.PHONY:    fclean re all clean