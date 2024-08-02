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
	check_av.c\
	push_swap.c\
	# operations/push.c\
	# operations/reverse.c\
	# operations/rotate.c\
	# operations/swap.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(PRINTF): | $(PRINTF_DIR)
			@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF)
			@$(CC) $(CFLAGS) -o $@ $(OBJ) $(PRINTF) $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) $(OBJ_DIR)
			@$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
		@$(RM) $(NAME)
		@$(MAKE) fclean -C $(PRINTF_DIR)

re:        fclean all

.PHONY:    fclean re all clean