/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:04:50 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/30 22:48:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_position(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
}

int	get_target(t_stack **stack_a, int value, int target_s, int target)
{
	t_stack	*aux_stack;

	aux_stack = *stack_a;
	while (aux_stack)
	{
		if (aux_stack->value > value && aux_stack->value < target_s)
		{
			target_s = aux_stack->value;
			target = aux_stack->index;
		}
		aux_stack = aux_stack->next;
	}
	if (target_s != INT_MAX)
		return (target);
	aux_stack = *stack_a;
	while (aux_stack)
	{
		if (aux_stack->value < target_s)
		{
			target_s = aux_stack->value;
			target = aux_stack->index;
		}
		aux_stack = aux_stack->next;
	}
	return (target);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	int		objective;
	t_stack	*iterate_b;

	objective = 0;
	iterate_b = *stack_b;
	set_position(*stack_a);
	set_position(*stack_b);
	while (iterate_b)
	{
		objective = get_target(stack_a, iterate_b->value, INT_MAX, objective);
		iterate_b->target = objective;
		iterate_b = iterate_b->next;
	}
}
