#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct s_temp
{
    int len_a;
    int len_b;
    int *stack_a;
    int *stack_b;
    int *tmp_stack_b;
    int top_b;
    int top_a;
}   t_temp;

void op_s(int *stack_a);
void op_rr(int *stack_a, int len);
void op_r(int *stack_a, int len);
void pb(t_temp *data);
void test(int *stack_a, int ac);
void pa(t_temp *data);
void sb(t_temp *data);
void sa(t_temp *data);
void rb(t_temp *data);
void ra(t_temp *data);
void rrb(t_temp *data);
void rra(t_temp *data);
void two_and_three(t_temp *data, int len);
void four_to_hundred(t_temp *data, int pivot);
int check_sorted(int *stack, int ac);
int check_pivot(t_temp *data, int pivot);
int sort_and_pivot(t_temp *data, int len);
void four_to_hundred_cont(t_temp *data);

/* test.c */
void	test_print_stack(t_temp *data);
void	test(int *stack_a, int ac);

#endif