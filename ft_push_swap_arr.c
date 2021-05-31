#include "includes/push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    int *stack;
	int i;

	i = 0;
    if (ac > 1)
	{
        stack = (int *)malloc(sizeof(int) * (ac - 1));
		while(*++av)
        {
			stack[i] = ft_atoi(*av);
			printf("[%d]\n", stack[i]);
			i++;
        }
	}
	else
		return (1);
}	