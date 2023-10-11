/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:23:27 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/11 11:27:08 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/stack.h"

void	s(t_stack **stack, char letter)
{
	t_stack	*aux;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	
	aux = (*stack)->next;
	(*stack)->next = aux->next;
	aux->next = (*stack);
	*stack = aux;
	printf("s%c\n", letter);
}

void	p(t_stack **origen, t_stack **dest, char letter)
{
	t_stack	*node;

	if (!origen || !(*origen) || !dest)
		return ;
	node = (*origen);
	*origen = (*origen)->next;

	node->next = (*dest);
	(*dest) = node;
	printf("p%c\n", letter);
}

void	r(t_stack **stack, char letter)
{
	t_stack	*node;
	t_stack	*current;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;

	node = (*stack);
	current = (*stack);
	while (current->next)
		current = current->next;
	current->next = node;
	(*stack) = (*stack)->next;
	node->next = NULL;
	printf("r%c\n", letter);
}

void	rr(t_stack **stack, char letter)
{
	t_stack	*node;

	if (!stack ||!(*stack) || !(*stack)->next)
		return ;

	node = *stack;
	while (node->next->next)
		node = node->next;
	node->next->next = (*stack);
	(*stack) = node->next;
	node->next = NULL;
	printf("rr%c\n", letter);
}
