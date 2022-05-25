NAME	=	Push_Swap

CC		= gcc

FLAGS	= -Wall -Werror -Wextra

SRC		= Moves.c Push_Swap.c Push_Swap_Utils.c Sorting.c moves2.c error.c utils.c big_sort.c

OBJ		=	$(SRC:.c=.o)

FLAGS	= -Wall -Werror -Wextra -g -fsanitize=address


RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)