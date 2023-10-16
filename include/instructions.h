#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "stack.h"

void	sa(t_stack **stack_a);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);

void	sb(t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	rrb(t_stack **stack_b);



#endif