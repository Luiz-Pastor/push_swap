#include "../include/stack.h"

void	order2(t_stack *stack)
{
	
}

void	manage_order(int argc, t_stack *stack)
{
	if (!stack)
		return ;
	if (argc == 2)
		order2(stack);
	else if (argc == 3)
		order3(stack);
	
	return ;
}