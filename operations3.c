#include "includes/push_swap.h"
#include <stdio.h>

void rra(t_temp *data)
{
    op_rr(data->stack_a, data->len_a);
    write(1, "rra\n", 4);
}

void rrb(t_temp *data)
{
    op_rr(data->stack_b, data->len_b);
    write(1, "rrb\n", 4);
}

void ra(t_temp *data)
{
    op_r(data->stack_a, data->len_a);
    write(1, "ra\n", 3);
}

void rb(t_temp *data)
{
    op_r(data->stack_b, data->len_b);
    write(1, "rb\n", 3);
}

void sa(t_temp *data)
{
    op_s(data->stack_a);
    write(1, "sa\n", 3);
}
