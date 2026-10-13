/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimo <tasnimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:10:26 by nmokashi          #+#    #+#             */
/*   Updated: 2026/08/13 13:51:39 by tasnimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

enum e_algo_mode
{
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
	MODE_ADAPTIVE
};

typedef struct s_flag
{
	int		algo_mode;
	int		bench;
	int		value_start;
	int		print_op;
}	t_flag;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disorder;
}	t_bench;

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	t_bench	bench;
}	t_stack;

typedef struct s_chunk
{
	t_stack	*stack;
	int		*sorted;
	int		size;
	int		chunk_size;
	int		chunk;
}	t_chunk;

void	pa(t_stack *stack, t_flag *flag);
void	pb(t_stack *stack, t_flag *flag);
void	sa(t_stack *stack, t_flag *flag, int print);
void	sb(t_stack *stack, t_flag *flag, int print);
void	ss(t_stack *stack, t_flag *flag);
void	ra(t_stack *stack, t_flag *flag, int print);
void	rb(t_stack *stack, t_flag *flag, int print);
void	rra(t_stack *stack, t_flag *flag, int print);
void	rrb(t_stack *stack, t_flag *flag, int print);
void	rr(t_stack *stack, t_flag *flag);
void	rrr(t_stack *stack, t_flag *flag);

int		is_sorted(int *a, int size_a);
void	minmax(t_stack *stack, t_flag *flag);
void	radix_sort(t_stack *stack, t_flag *flag);

void	medium_sort(t_stack *stack, t_flag *flag);
void	push_chunk(t_chunk *data, t_flag *flag);
int		get_chunk(int value, int *sorted, int size, int chunk_size);
int		get_chunk_size(int size);
int		*create_sorted_array(int *a, int size);
int		find_max_position(int *arr, int size);
void	push_max_back(t_stack *stack, t_flag *flag);

void	validate_args(char **argv);
void	check_duplicates(int *a, int size_a);

double	measure_disorder(int *a, int size);
void	adaptive_sort(t_stack *stacks, t_flag *flags);

void	map_values(int *a, int size);
void	parse_options(int argc, char **argv, t_flag *flags);
int		init_stack(int **a, int **b, int size);
void	init_bench(t_bench *bench);
void	print_bench(t_stack *stack, t_flag *flag);
void	print_str_fd(int fd, const char *str);
void	print_nbr_fd(int fd, int n);
void	print_float2_fd(int fd, double n);
char	**get_values(int argc, char **argv, t_flag *flags, int *count);
