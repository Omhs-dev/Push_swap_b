NAME = push_swap
BONUS_NAME = checker

SRCS = ./src/main.c \
	./src/operations/push_stack.c ./src/operations/reverse_rotate_s.c ./src/operations/rotate_stack.c \
	./src/operations/swap_stack.c ./src/sorting/sort_small.c ./src/sorting/sort.c \
	./src/utils/stack_comp.c ./src/utils/cost.c ./src/utils/errors.c ./src/utils/init.c \
	./src/utils/input.c ./src/utils/movements.c ./src/utils/pos.c ./src/utils/utils.c \
	./src/utils/utils1.c ./src/utils/split.c

SRC_B = ./bonus/checker.c ./bonus/checker_utils.c ./bonus/get_next_line_bonus.c \
		./bonus/get_next_line_utils_bonus.c \
		./src/operations/push_stack.c ./src/operations/reverse_rotate_s.c \
		./src/operations/rotate_stack.c \
		./src/operations/swap_stack.c \
		./src/utils/stack_comp.c ./src/utils/cost.c ./src/utils/errors.c ./src/utils/init.c \
		./src/utils/input.c ./src/utils/movements.c ./src/utils/pos.c ./src/utils/utils.c \
		./src/utils/utils1.c ./src/utils/split.c

RM = rm -f

INCS	= -I ./includes/

CC = gcc

FLAGS = -g -Wall -Wextra -Werror #-fsanitize=address -static-libsan

OBJS = $(SRCS:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

$(NAME):	$(OBJS)
		@${CC} $(FLAGS) $(SRCS) -o push_swap
		
$(BONUS_NAME) : $(OBJ_B)
		@${CC} $(FLAGS) $(SRC_B) -o checker

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
		@$(RM) $(OBJS) $(OBJ_B)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)

re: fclean all


.PHONY : all clean fclean re bonus
