#include "includes/push_swap.h"
#include <stdio.h>

void	main_continue(t_temp *data, int len)
{
	if (len == 2 || len == 3)
		two_and_three(data, len);
	else if (len > 3 && len <= 5)
		four_and_five(data, len);
}

void	init_struct(int *stack, int *stack_b, int ac)
{
	t_temp	*data;

	data = malloc(sizeof(t_temp));
	data->len_a = ac;
	data->len_b = 0;
	data->stack_a = stack;
	data->stack_b = stack_b;
	main_continue(data, ac);
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
	while (ac-- > 0)
	{
		if (stack[ac] < stack[ac - 1])
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
			if (!check_errors(stack, stack[i], i, *av))
				return (1);
			if (!check_sorted(stack, ac - 1))
				return (1);
			i++;
		}
		init_struct(stack, stack_b, ac - 1);
		return (0);
	}
	else
		return (1);
}
