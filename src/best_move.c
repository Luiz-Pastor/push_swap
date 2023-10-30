/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:02:00 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/30 14:16:59 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	db_op(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	if ((*cost_a) < 0 && (*cost_b) < 0)
	{
		while ((*cost_a) < 0 && (*cost_b) < 0)
		{
			(*cost_a)++;
			(*cost_b)++;
			rrr(stack_a, stack_b, 1);
		}
	}
	else if ((*cost_a) > 0 && (*cost_b) > 0)
	{
		while ((*cost_a) > 0 && (*cost_b) > 0)
		{
			(cost_a)--;
			(cost_b)--;
			rr(stack_a, stack_b, 1);
		}
	}
}

void	sg_op(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while ((*cost_a))
	{
		if ((*cost_a) > 0)
		{
			ra(stack_a, 1);
			(*cost_a)--;
		}
		else if ((*cost_a) < 0)
		{
			rra(stack_a, 1);
			(*cost_a)++;
		}
	}
	while ((*cost_b))
	{
		if ((*cost_b) > 0)
		{
			rb(stack_b, 1);
			(*cost_b)--;
		}
		else if ((*cost_b) < 0)
		{
			rrb(stack_b, 1);
			(*cost_b)++;
		}
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if ((cost_a) < 0 && (cost_b) < 0)
	{
		while ((cost_a) < 0 && (cost_b) < 0)
		{
			(cost_a)++;
			(cost_b)++;
			rrr(stack_a, stack_b, 1);
		}
	}
	else if ((cost_a) > 0 && (cost_b) > 0)
	{
		while ((cost_a) > 0 && (cost_b) > 0)
		{
			(cost_a)--;
			(cost_b)--;
			rr(stack_a, stack_b, 1);
		}
	}
		while ((cost_a))
	{
		if ((cost_a) > 0)
		{
			ra(stack_a, 1);
			(cost_a)--;
		}
		else if ((cost_a) < 0)
		{
			rra(stack_a, 1);
			(cost_a)++;
		}
	}
	while ((cost_b))
	{
		if ((cost_b) > 0)
		{
			rb(stack_b, 1);
			(cost_b)--;
		}
		else if ((cost_b) < 0)
		{
			rrb(stack_b, 1);
			(cost_b)++;
		}
	}
	pa(stack_b, stack_a, 1);
}

int	ft_abs(int number)
{
	if (number < 0)
		return (number *= -1);
	return (number);
}

void	best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_b;
	int		best;
	int		aux_cost_a;
	int		aux_cost_b;

	aux_b = *stack_b;
	best = INT_MAX;
	while (aux_b)
	{
		if (ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_b) < best)
		{
			best = ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_b);
			aux_cost_a = aux_b->cost_a;
			aux_cost_b = aux_b->cost_b;
		}
		aux_b = aux_b->next;
	}
	do_move(stack_a, stack_b, aux_cost_a, aux_cost_b);
}
