/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:07:44 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/16 09:42:24 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/stack.h"
#include "../include/instructions.h"

int	get_max_element(t_stack *head)
{
	int	max;
	
	max = *(int*)head->content;
	head = head->next;
	while (head != NULL)
	{
		if (*(int*)head->content > max)
			max = *(int*)head->content;
		head = head->next;
	}
	return (max);
}

int	get_min_element(t_stack *head)
{
	int	min;
	
	min = *(int*)head->content;
	head = head->next;
	while (head != NULL)
	{
		if (*(int*)head->content < min)
			min = *(int*)head->content;
		head = head->next;
	}
	return (min);
}

void	order3(t_stack **head)
{
	int max;

	max = get_max_element(*head);
	if (*(int*)(*head)->content == max)
		ra(head);
	else if (*(int*)(*head)->next->content ==	 max)
		rra(head);
	if (*(int*)(*head)->content > *(int*)(*head)->next->content)
		sa(head);
}

void	order4(t_stack **head)
{
	t_stack	*stack_b;
	int min;

	stack_b = NULL;
	min = get_min_element(*head);
	if (*(int*)(*head)->content == min)
		pb(head, &stack_b);
	else if (*(int*)(*head)->next->content == min)
	{
		ra(head);
		pb(head, &stack_b);
	}
	else if (*(int*)(*head)->next->next->content == min)
	{
		ra(head);
		ra(head);
		pb(head, &stack_b);
	}
	else
	{
		rra(head);
		pb(head, &stack_b);
	}
	
	order3(head);
	
	if (*(int*)stack_b->content < *(int*)(*head)->content)
		pa(&stack_b, head);
	else if (*(int*)stack_b->content < *(int*)(*head)->next->content)
	{
		pa(&stack_b, head);
		sa(head);
	}
	else if (*(int*)stack_b->content < *(int*)(*head)->next->content)
	{
		rra(head);
		pa(&stack_b, head);
		ra(head);
		ra(head);
	}
	else
	{
		pa(&stack_b, head);
		ra(head);
	}
}

void	order5(t_stack **head)
{
	*head = NULL;
}

void	manage_order(t_stack **stack, int argc)
{
	if (!stack)
		return ;
	if (argc == 2)
		sa(stack);
	else if (argc == 3)
		order3(stack);
	else if (argc == 4)
		order4(stack);
	else if (argc == 5)
		order5(stack);
	else
		return ;
	return ;
}
