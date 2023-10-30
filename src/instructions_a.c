/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:23:27 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/30 09:25:33 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sa(t_stack **stack_a, int print)
{
	t_stack	*aux;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (1);
	aux = (*stack_a)->next;
	(*stack_a)->next = aux->next;
	aux->next = (*stack_a);
	*stack_a = aux;
	(*stack_a)->prev = NULL;
	(*stack_a)->next->prev = *stack_a;
	if (print)
		write(1, "sa\n", 3);
	return (1);
}

int	pa(t_stack **stack_b, t_stack **stack_a, int print)
{
	t_stack	*node;

	if (!stack_b || !(*stack_b) || !stack_a)
		return (1);
	node = (*stack_b);
	*stack_b = (*stack_b)->next;
	node->next = (*stack_a);
	(*stack_a) = node;
	if (print)
		write(1, "pa\n", 3);
	return (1);
}

int	ra(t_stack **stack_a, int print)
{
	t_stack	*node;
	t_stack	*current;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (1);
	node = (*stack_a);
	current = (*stack_a);
	while (current->next)
		current = current->next;
	current->next = node;
	node->prev = current;
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	node->next = NULL;
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rra(t_stack **stack_a, int print)
{
	t_stack	*node;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (1);
	node = *stack_a;
	while (node->next->next)
		node = node->next;
	node->next->next = (*stack_a);
	(*stack_a) = node->next;
	(*stack_a)->prev = NULL;
	node->next = NULL;
	if (print)
		write(1, "rra\n", 4);
	return (1);
}
