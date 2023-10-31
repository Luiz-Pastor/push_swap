/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:02:00 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/31 08:05:44 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	db_op(t_stack **stack_a, t_stack **stack_b, int *mv_sa, int *mv_sb)
{
	if ((*mv_sa) > 0 && (*mv_sb) > 0)
	{
		while ((*mv_sa) > 0 && (*mv_sb) > 0)
		{
			(*mv_sa)--;
			(*mv_sb)--;
			rr(stack_a, stack_b, 1);
		}
	}
	else if ((*mv_sa) < 0 && (*mv_sb) < 0)
	{
		while ((*mv_sa) < 0 && (*mv_sb) < 0)
		{
			(*mv_sa)++;
			(*mv_sb)++;
			rrr(stack_a, stack_b, 1);
		}
	}
}

void	sg_a_op(t_stack **stack_a, int *mv_sa)
{
	while ((*mv_sa))
	{
		if ((*mv_sa) > 0)
		{
			ra(stack_a, 1);
			(*mv_sa)--;
		}
		else if ((*mv_sa) < 0)
		{
			rra(stack_a, 1);
			(*mv_sa)++;
		}
	}
}

void	sg_op(t_stack **stack_a, t_stack **stack_b, int *mv_sa, int *mv_sb)
{
	while ((*mv_sb))
	{
		if ((*mv_sb) > 0)
		{
			rb(stack_b, 1);
			(*mv_sb)--;
		}
		else if ((*mv_sb) < 0)
		{
			rrb(stack_b, 1);
			(*mv_sb)++;
		}
	}
	sg_a_op(stack_a, mv_sa);
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int mv_sa, int mv_sb)
{
	db_op(stack_a, stack_b, &mv_sa, &mv_sb);
	sg_op(stack_a, stack_b, &mv_sa, &mv_sb);
	pa(stack_b, stack_a, 1);
}

void	best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_b;
	int		best;
	int		aux_mv_sa;
	int		aux_mv_sb;

	aux_b = *stack_b;
	best = INT_MAX;
	while (aux_b)
	{
		if (ft_abs(aux_b->mv_sa) + ft_abs(aux_b->mv_sb) < best)
		{
			best = ft_abs(aux_b->mv_sa) + ft_abs(aux_b->mv_sb);
			aux_mv_sa = aux_b->mv_sa;
			aux_mv_sb = aux_b->mv_sb;
		}
		aux_b = aux_b->next;
	}
	do_move(stack_a, stack_b, aux_mv_sa, aux_mv_sb);
}
