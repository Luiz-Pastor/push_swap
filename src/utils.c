/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:11:19 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/30 23:24:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_ordered(t_stack	*stack)
{
	int	prev;
	int	current;

	if (!stack)
		return (1);
	prev = *stack->content;
	stack = stack->next;
	while (stack)
	{
		current = *stack->content;
		if (prev > current)
			return (0);
		prev = current;
		stack = stack->next;
	}
	return (1);
}

void	*int_copy(int elem)
{
	int	*cpy;

	cpy = (int *) malloc(sizeof(int));
	if (!cpy)
		return (NULL);
	*cpy = elem;
	return (cpy);
}

void	*ft_matrix_free(char **elem)
{
	char	**head;

	if (!elem)
		return (NULL);
	head = elem;
	while (*elem)
	{
		free(*elem);
		elem++;
	}
	free(head);
	return (NULL);
}

int	ft_abs(int number)
{
	if (number < 0)
		return (number *= -1);
	return (number);
}
