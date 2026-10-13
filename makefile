NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	src/main.c \
	src/operations/swap.c \
	src/operations/push.c \
	src/operations/rotate_a.c \
	src/operations/rotate_b.c \
	src/algo/medium.c \
	src/algo/minmax.c \
	src/algo/radix.c \
	src/algo/adaptive.c \
	src/utils/radix_utils.c \
	src/utils/algo_medium_utils.c \
	src/utils/helpers.c \
	src/utils/error_handling.c \
	src/utils/check_duplicates.c \
	src/utils/adaptive_utils.c \
	src/utils/main_arg_utils.c \
	src/utils/bench_utils.c \
	src/utils/bench_print_utils.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_putchar.c \
	ft_printf/ft_puthex.c \
	ft_printf/ft_putnbr.c \
	ft_printf/ft_putnbrunsigned.c \
	ft_printf/ft_putptr.c \
	ft_printf/ft_putstr.c \
	libft/ft_atoi.c \
	libft/ft_isdigit.c \
	libft/ft_split.c \
	libft/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -Ilibft -Ift_printf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
