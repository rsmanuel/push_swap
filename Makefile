NAME = push_swap

FLAGS = -Wall -Werror -Wextra

SRCS = ft_push_swap.c \
       ft_push_swap_aux.c \
       logic.c \
       logic2.c \
       operations.c \
       operations2.c \
       operations3.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	    make -C ./libft
	    gcc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)	   
all: $(NAME)

clean:
	make clean -C ./libft
	rm -rf *.o
	rm -rf $(OBJS)

fclean:
	make fclean -C ./libft
	rm -rf *.o
	rm $(NAME)
	rm libft.a

re: fclean all
