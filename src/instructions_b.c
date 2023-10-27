/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:31:57 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/25 10:59:08 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/stack.h"

int	sb(t_stack **stack_b, int print)
{
	t_stack	*aux;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return (1);
	aux = (*stack_b)->next;
	(*stack_b)->next = aux->next;
	aux->next = (*stack_b);
	*stack_b = aux;
	if (print)
		printf("sb\n");
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*node;

	if (!stack_a || !(*stack_a) || !stack_b)
		return (1);
	node = (*stack_a);
	*stack_a = (*stack_a)->next;
	node->next = (*stack_b);
	(*stack_b) = node;
	if (print)
		printf("pb\n");
	return (1);
}

int	rb(t_stack **stack_b, int print)
{
	t_stack	*node;
	t_stack	*current;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (1);
	node = (*stack_b);
	current = (*stack_b);
	while (current->next)
		current = current->next;
	current->next = node;
	(*stack_b) = (*stack_b)->next;
	node->next = NULL;
	if (print)
		printf("rb\n");
	return (1);
}

int	rrb(t_stack **stack_b, int print)
{
	t_stack	*node;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (1);
	node = *stack_b;
	while (node->next->next)
		node = node->next;
	node->next->next = (*stack_b);
	(*stack_b) = node->next;
	node->next = NULL;
	if (print)
		printf("rrb\n");
	return (1);
}
