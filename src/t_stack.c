#include "../include/stack.h"

#include <stdio.h>

t_stack	*ft_stack_create(void *content)
{
	t_stack	*node;

	node = (t_stack*) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_stack_delete(t_stack **head, void (*delete)(void*))
{
	t_stack	*aux;

	if (!head)
		return ;
	while (*head)
	{
		aux = *head;
		*head = (*head)->next;
		if (delete)
			delete(aux->content);
		free(aux);
	}
	*head = NULL;
}

void	ft_stack_updateindex(t_stack *head)
{
	size_t	index;
	if (!head)
		return ;
	index = 0;
	while (head)
	{
		head->index = index;
		index++;
		head = head->next;
	}
}

void	ft_stack_print(t_stack *stack, void (*print)(void*))
{
	size_t	count;

	if (!stack | !print)
		return ;
	count = 0;
	while (stack)
	{
		printf("(Node %zu): ", stack->index);
		print(stack->content);
		printf("\n");
		stack = stack->next;
		count++;
	}
}

void	ft_stack_addfront(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	node->next = *stack;
	(*stack)->prev = node;
	*stack = node;
}

void	ft_stack_addback(t_stack **stack, t_stack *node)
{
	t_stack	*current;

	if (!stack || !node)
		return ;
	current = *stack;
	if (!current)
	{
		*stack = node;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = node;
	node->prev = current;
}

t_stack	*ft_stack_popfront(t_stack **stack)
{
	t_stack	*data;

	if (!stack || !(*stack))
		return (NULL);

	// Cogemos el primer elemento
	data = (*stack);

	// Cambiamos la primera posicion
	*stack = (*stack)->next;
	data->next = NULL;
	if (*stack)
		(*stack)->prev = NULL;
	return (data);
}

t_stack	*ft_stack_popback(t_stack **stack)
{
	t_stack *current;

	if (!stack || !(*stack))
		return (NULL);
	if (!(*stack)->next)
	{
		current = *stack;
		current->next = NULL;
		*stack = NULL;
		return (current);
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	return (current);
}
