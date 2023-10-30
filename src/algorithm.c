/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:02:07 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/30 09:02:07 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = ft_stacksize(*stack_a);
	pushes = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
	{
		if ((*stack_a)->pos_value <= stack_size / 2)
		{
			pb(stack_a, stack_b, 1);
			pushes++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
	while (stack_size - pushes > 3)
	{
		pb(stack_a, stack_b, 1);
		pushes++;
	}
}

void	move_min(t_stack **stack)
{
	int	length;
	int	min_index;

	length = ft_stacksize(*stack);
	min_index = get_min_index(*stack);
	if (min_index < (length / 2))
	{
		while (!is_ordered(*stack))
		{
			ra(stack, 1);
		}
	}
	else
	{
		while (!is_ordered(*stack))
			rra(stack, 1);
	}
}
#include <stdio.h>
void	algorithm(t_stack **stack_a)
{
	t_stack	*stack_b;
	stack_b = NULL;
	push_init(stack_a, &stack_b);
	order3(stack_a);
	while (stack_b)
	{
		get_target_position(stack_a, &stack_b);
		check_cost(stack_a, &stack_b);
		best_move(stack_a, &stack_b);
	}
	if (!is_ordered(*stack_a))
		move_min(stack_a);
}
