/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:07:44 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/11 11:59:55 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"
#include "../include/instructions.h"

void	order3(t_stack **head)
{
	t_stack	*stack = *head;
	if (*(int*)stack->content > *(int*)stack->next->content && \
		*(int*)stack->content > *(int*)stack->next->next->content)
		r(head, 'a');
	else if (*(int*)stack->next->content > *(int*)stack->content && \
		*(int*)stack->next->content > *(int*)stack->next->next->content)
		rr(head, 'a');
	if (*(int*)stack->content > *(int*)stack->next->content)
		s(head, 'a');
}

void	manage_order(t_stack **stack, int argc)
{
	if (!stack)
		return ;
	if (argc == 2)
		s(stack, 'a');
	else if (argc == 3)
		order3(stack);
	return ;
}