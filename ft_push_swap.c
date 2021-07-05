#include "includes/push_swap.h"
#include <stdio.h>

void	main_continue(t_temp *data, int len)
{
	if (len == 2 || len == 3)
		two_and_three(data, len);
	else if (len > 3 && len < 101)
		four_to_hundred(data, sort_and_pivot(data, data->len_a));
}

void	init_struct(int *stack, int *stack_b, int ac)
{
	t_temp	*data;

	data = malloc(sizeof(t_temp));
	data->len_a = ac;
	data->len_b = 0;
	data->stack_a = stack;
	data->stack_b = stack_b;
	test_print_stack(data);
	main_continue(data, ac);
	test_print_stack(data);
	free(data);
}

int	check_errors(int *stack, int num, int i, char *av)
{
	int	j;

	j = 0;
	while (i-- > 0)
	{
		if (stack[i] == num || !ft_atoi(av))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	check_sorted(int *stack, int ac)
{
	int i;

	i = ac;
	while (i-- > 0)
	{
		if (stack[i] < stack[i - 1])
			return (1);
	}
	return (0);
} 

int	main(int ac, char **av)
{
	int	*stack;
	int	*stack_b;
	int	i;

	i = 0;
	if (ac > 1)
	{
		stack = (int *)malloc(sizeof(int) * (ac - 1));
		stack_b = (int *)malloc(sizeof(int) * (ac - 1));
		if (!stack)
			return (1);
		while (*++av)
		{
			stack[i] = ft_atoi(*av);
			if (!check_errors(stack, stack[i], i, *av) && !check_sorted(stack, ac - 1))
			{
				free(stack);
				free(stack_b);
				return (1);
			}
			i++;
		}
		init_struct(stack, stack_b, ac - 1);
		free(stack);
		free(stack_b);
		return (0);
	}
	else
		return (1);
}
