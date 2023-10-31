/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:06:01 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/31 08:15:26 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_movements_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stacksize(tmp_a);
	size_b = ft_stacksize(tmp_b);
	while (tmp_b)
	{
		tmp_b->mv_sb = tmp_b->index;
		if (tmp_b->index > size_b / 2)
			tmp_b->mv_sb = (size_b - tmp_b->index) * -1;
		tmp_b->mv_sa = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->mv_sa = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}
