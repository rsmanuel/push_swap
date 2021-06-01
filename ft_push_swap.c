#include "includes/push_swap.h"
#include <stdio.h>

void	test(int *stack_a, int ac, int i)
{
	printf("after ra:\n");
		stack_a = op_r(stack_a, ac - 1);
		i = 0;
		while(i < ac - 1)
		{
			printf("[%d]\n", stack_a[i]);
			i++;
		}
}
int main(int ac, char **av)
{
    int *stack_a;
	int i;

	i = 0;
    if (ac > 1)
	{
        stack_a = (int *)malloc(sizeof(int) * (ac - 1));
		while(*++av)
		{
			stack_a[i] = ft_atoi(*av);
			printf("[%d]\n", stack_a[i]);
			i++;
		}
		test(stack_a, ac, i);
	}
	else
		return (1);
}	