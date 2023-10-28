/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:07:44 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/28 23:37:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"
#include "../include/instructions.h"
#include "../include/utils.h"
#include "../include/algorithm.h"

void	order3(t_stack **head)
{
	int	max;

	max = get_max_element(*head);
	if (*(int *)(*head)->content == max)
		ra(head, 1);
	else if (*(int *)(*head)->next->content == max)
		rra(head, 1);
	if (*(int *)(*head)->content > *(int *)(*head)->next->content)
		sa(head, 1);
}

void	order4(t_stack **head)
{
	t_stack	*stack_b;
	int		min;
	
	stack_b = NULL;
	min = get_min_element(*head);
	if (*(int *)(*head)->next->content == min)
		ra(head, 1);
	else if (*(int *)(*head)->next->next->content == min)
	{
		ra(head, 1);
		ra(head, 1);
	}
	else if (*(int *)(*head)->next->next->next->content == min)
		rra(head, 1);
	if (is_ordered(*head))
		return ;
	pb(head, &stack_b, 1);
	order3(head);
	pa(&stack_b, head, 1);
}

void	order5(t_stack **head)
{
	t_stack	*stack_b;
	int		min;

	stack_b = NULL;
	min = get_min_element(*head);
	if (*(int *)(*head)->next->content == min)
		ra(head, 1);
	else if (*(int *)(*head)->next->next->content == min)
	{
		ra(head, 1);
		ra(head, 1);
	}
	else if (*(int *)(*head)->next->next->next->content == min)
	{
		rra(head, 1);
		rra(head, 1);
	}
	else if (*(int *)(*head)->next->next->next->next->content == min)
		rra(head, 1);
	if (is_ordered(*head))
		return ;
	pb(head, &stack_b, 1);
	order4(head);
	pa(&stack_b, head, 1);
}

void	manage_order(t_stack **stack)
{
	int	arguments;

	arguments = ft_stacksize(*stack);
	if (!stack)
		return ;
	if (arguments == 2)
		sa(stack, 1);
	else if (arguments == 3)
		order3(stack);
	else if (arguments == 4)
		order4(stack);
	else if (arguments == 5)
		order5(stack);
	else
		algorithm(stack);
	return ;
}
