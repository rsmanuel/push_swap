#include "includes/push_swap.h"
#include <stdio.h>

void	test(int *stack_a, int ac)
{
	int	i;

	i = 0;
	while (stack_a && i < ac)
	{
		printf("[%d]\n", stack_a[i]);
		i++;
	}
}

void	test_print_stack(t_temp *data)
{
	printf("\n");
	printf("stack_a:\n");
	test(data->stack_a, data->len_a);
	printf("stack_b:\n");
	test(data->stack_b, data->len_b);
}

void	test_print_struct(t_temp *data)
{
	printf("len_a: %d\n", data->len_a);
	printf("len_b: %d\n", data->len_b);
}

void	main_continue(t_temp *data)
{
	test_print_stack(data);
	op_pb(data);
	test_print_stack(data);
	op_r(data->stack_b, data->len_b);
	test_print_stack(data);
	op_r(data->stack_b, data->len_b);
	test_print_stack(data);
	op_rr(data->stack_a, data->len_a);
	test_print_stack(data);
	op_pa(data);
	test_print_stack(data);
}

void	init_struct(int *stack, int *stack_b, int ac)
{
	t_temp	*data;

	data = malloc(sizeof(t_temp));
	data->len_a = ac;
	data->len_b = 0;
	data->stack_a = stack;
	data->stack_b = stack_b;
	main_continue(data);
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
	while (ac-- > 1)
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
