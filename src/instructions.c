#include "../include/stack.h"

void	sa(t_stack	**stack)
{
	t_stack	*aux;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	aux = (*stack)->next;
	// Enlazamos el primero y el tercero
	(*stack)->next = aux->next;
	if (aux->next)
		aux->next->prev = *stack;
	// Enlazamos el segundo al primero
	aux->next = *stack;
	aux->prev = NULL;
	(*stack)->prev = aux;
	// Cambiamos la cabeza
	*stack = aux;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	node = ft_stack_popfront(stack_a);
	ft_stack_addfront(stack_b, node);
}

void	ra(t_stack **stack)
{
	t_stack	*node;

	node = ft_stack_popfront(stack);
	ft_stack_addback(stack, node);
}

void	rra(t_stack **stack)
{
	t_stack	*node;

	node = ft_stack_popback(stack);
	ft_stack_addfront(stack, node);
}
