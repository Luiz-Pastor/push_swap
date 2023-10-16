/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:23:27 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/16 09:31:05 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/stack.h"

void	sa(t_stack **stack_a)
{
	t_stack	*aux;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	
	aux = (*stack_a)->next;
	(*stack_a)->next = aux->next;
	aux->next = (*stack_a);
	*stack_a = aux;
	printf("sa\n");
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*node;

	if (!stack_b || !(*stack_b) || !stack_a)
		return ;
	node = (*stack_b);
	*stack_b = (*stack_b)->next;

	node->next = (*stack_a);
	(*stack_a) = node;
	printf("pa\n");
}

void	ra(t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*current;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;

	node = (*stack_a);
	current = (*stack_a);
	while (current->next)
		current = current->next;
	current->next = node;
	(*stack_a) = (*stack_a)->next;
	node->next = NULL;
	printf("ra\n");
}

void	rra(t_stack **stack_a)
{
	t_stack	*node;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;

	node = *stack_a;
	while (node->next->next)
		node = node->next;
	node->next->next = (*stack_a);
	(*stack_a) = node->next;
	node->next = NULL;
	printf("rra\n");
}
