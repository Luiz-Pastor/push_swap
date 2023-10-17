#ifndef ORDER_H
# define ORDER_H

# include "stack.h"

int		is_ordered(t_stack	*stack);
void	manage_order(t_stack **stack, int count);

#endif