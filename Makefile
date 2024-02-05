NAME 	= push_swap

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g

SRCS 	=	main.c utils/check_args.c utils/utils.c \
			mini_libft/ft_atoi.c mini_libft/ft_isdigit.c mini_libft/ft_split.c mini_libft/ft_calloc.c mini_libft/ft_bzero.c mini_libft/ft_memset.c\
			utils/ordering.c utils/moves.c utils/moves2.c utils/moves3.c utils/moves4.c utils/sorting.c utils/sorting2.c utils/calculate.c\

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)


%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all