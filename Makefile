NAME	=	Push_Swap

BNAME	= checker

CC		= gcc

FLAGS	= -Wall -Werror -Wextra

SRC		= 	./Push_swap/srcs/Moves.c \
			./Push_swap/srcs/main.c \
			./Push_swap/srcs/Push_Swap.c \
			./Push_swap/srcs/Push_Swap_Utils.c \
			./Push_swap/srcs/Sorting.c \
			./Push_swap/srcs/moves2.c \
			./Push_swap/srcs/error.c \
			./Push_swap/srcs/utils.c \
			./Push_swap/srcs/big_sort.c

BONUS	= 	./Push_swap_bonus/srcs/checker.c \
			./Push_swap_bonus/srcs/Moves.c \
			./Push_swap_bonus/srcs/Push_Swap.c \
			./Push_swap_bonus/srcs/Push_Swap_Utils.c \
			./Push_swap_bonus/srcs/Sorting.c \
			./Push_swap_bonus/srcs/moves2.c \
			./Push_swap_bonus/srcs/error.c \
			./Push_swap_bonus/srcs/utils.c \
			./Push_swap_bonus/srcs/get_next_line_utils.c \
			./Push_swap_bonus/srcs/get_next_line.c

BOBJ	= $(BONUS:.c=.o)

OBJ		=	$(SRC:.c=.o)

FLAGS	= -Wall -Werror -Wextra -g


RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(FLAGS) -o $(NAME)

bonus: $(BOBJ)
	$(CC) $(BOBJ) $(FLAGS) -o $(BNAME)

clean:
	$(RM) $(OBJ) $(BOBJ) 

fclean:	clean
		$(RM) $(NAME) $(BNAME)

re:	fclean $(NAME)