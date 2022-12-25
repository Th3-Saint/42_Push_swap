NAME	=	Push_Swap

BNAME	= checker

CC		= gcc

FLAGS	= -Wall -Werror -Wextra

SRC		= Moves.c main.c Push_Swap.c Push_Swap_Utils.c Sorting.c moves2.c error.c utils.c big_sort.c

BONUS	= checker.c Moves.c Push_Swap.c Push_Swap_Utils.c Sorting.c moves2.c error.c utils.c get_next_line_utils.c get_next_line.c

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