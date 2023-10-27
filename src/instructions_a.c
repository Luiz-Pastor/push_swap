/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:23:27 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/25 10:58:28 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/stack.h"

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
		printf("sa\n");
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
		printf("pa\n");
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
		printf("ra\n");
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
		printf("rra\n");
	return (1);
}
