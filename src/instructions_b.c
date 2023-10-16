/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:31:57 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/16 09:34:25 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "../include/stack.h"

void	sb(t_stack **stack_b)
{
	t_stack	*aux;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	
	aux = (*stack_b)->next;
	(*stack_b)->next = aux->next;
	aux->next = (*stack_b);
	*stack_b = aux;
	printf("sb\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	node = (*stack_a);
	*stack_a = (*stack_a)->next;

	node->next = (*stack_b);
	(*stack_b) = node;
	printf("pb\n");
}

void	rb(t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*current;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;

	node = (*stack_b);
	current = (*stack_b);
	while (current->next)
		current = current->next;
	current->next = node;
	(*stack_b) = (*stack_b)->next;
	node->next = NULL;
	printf("rb\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack	*node;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;

	node = *stack_b;
	while (node->next->next)
		node = node->next;
	node->next->next = (*stack_b);
	(*stack_b) = node->next;
	node->next = NULL;
	printf("rrb\n");
}
