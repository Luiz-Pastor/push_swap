#include <unistd.h>
#include "../include/stack.h"
#include "../include/instructions.h"

int ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, print);
	sb(stack_b, print);
	return (1);
}

int rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ra(stack_a, print);
	rb(stack_b, print);
	return (1);
}

int rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rra(stack_a, print);
	rrb(stack_b, print);
	return (1);
}