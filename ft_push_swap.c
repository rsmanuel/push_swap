#include <stdio.h>

int main(int ac, char **av)
{
    char	stack_a[1];
	int i;
	int j;

	i = 1;
	j = 0;
	av[1] = &stack_a[0];
	printf("%c", stack_a[0]);
}