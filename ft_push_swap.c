#include "includes/push_swap.h"
#include <stdio.h>

void print(t_stack *head)
{
	while (head)
	{
		printf("| %d | \n", head->data);
		head = head->next;
	}
}
/* Função para inserir a node no inicio
da linked list */
void stack(t_stack **head, int data)
{
	t_stack *new;
	
	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = data;
	new->prev = NULL;
	new->next = (*head);
	(*head) = new; 
}

int main(int ac, char **av)
{
	t_stack *data;
	int count;

	data = NULL;
	count = 0;
    if (ac > 1)
	{
		while(*++av)
		{
			stack(&data , ft_atoi(*av));
			count++;
		}
		print(data);
	}
	else
		return (1);
}	