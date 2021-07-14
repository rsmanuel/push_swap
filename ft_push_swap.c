#include "includes/push_swap.h"

void	main_continue(t_temp *data, int len)
{
	int	where;

	where = 0;
	if (len == 2 || len == 3)
		two_and_three(data, len);
	else if (len > 3 && len < 101)
	{
		four_to_hundred(data, sort_and_pivot(data, data->len_a));
		two_and_three(data, data->len_a);
		while (data->len_b > 0)
			four_to_hundred_cont(data);
	}
	else if (len > 100)
	{
		four_to_hundred(data, sort_and_pivot(data, data->len_a));
		two_and_three(data, data->len_a);
		while (data->len_b > 0)
			four_to_hundred_cont(data);
	}
}

void	init_struct(int *stack, int *stack_b, int ac)
{
	t_temp	*data;

	data = malloc(sizeof(t_temp));
	data->ac = ac;
	data->len_a = ac;
	data->len_b = 0;
	data->stack_a = stack;
	data->stack_b = stack_b;
	main_continue(data, ac);
	free(data);
}

void	free_stacks(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
}

int	main_aux(int i, char **av, int *stack, int *stack_b)
{
	while (*++av)
	{
		if (check_errors_aux(*av))
		{
			free_stacks(stack, stack_b);
			return (1);
		}
		stack[i] = ft_atoi(*av);
		i++;
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
		if (!stack || !stack_b)
			return (1);
		if (main_aux(i, av, stack, stack_b))
			return (1);
		if (check_errors_cont(stack, ac - 1) || check_errors(stack, ac - 1))
		{
			free_stacks(stack, stack_b);
			return (1);
		}
		init_struct(stack, stack_b, ac - 1);
		free_stacks(stack, stack_b);
		return (0);
	}
	return (1);
}
