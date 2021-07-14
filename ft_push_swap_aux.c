#include "includes/push_swap.h"

int	check_errors_aux(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '-')
			i++;
		if (!ft_isdigit(arg[i]) || (!ft_atoi(arg) && arg[i] != '0'))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_errors_cont(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < len - 1)
	{
		j = 0;
		while (j < len)
		{
			if (j == i)
				j++;
			if (stack[j] == stack[i])
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			break ;
		i++;
	}
	if (i == (len - 1))
		return (1);
	return (0);
}

int	check_sorted(int *stack, int ac)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		if (stack[i] < stack[i - 1])
			return (1);
		i--;
	}
	return (0);
}
