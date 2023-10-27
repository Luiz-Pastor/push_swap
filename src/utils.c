/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:11:19 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/27 09:16:16 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	is_ordered(t_stack	*stack)
{
	int	prev;
	int	current;

	if (!stack)
		return (1);
	prev = *(int *)stack->content;
	stack = stack->next;
	while (stack)
	{
		current = *(int *)stack->content;
		if (prev > current)
			return (0);
		prev = current;
		stack = stack->next;
	}
	return (1);
}

int	get_min_element(t_stack *head)
{
	int	min;

	min = *(int *)head->content;
	head = head->next;
	while (head != NULL)
	{
		if (*(int *)head->content < min)
			min = *(int *)head->content;
		head = head->next;
	}
	return (min);
}

int	get_max_element(t_stack *head)
{
	int	max;

	max = *(int *)head->content;
	head = head->next;
	while (head != NULL)
	{
		if (*(int *)head->content > max)
			max = *(int *)head->content;
		head = head->next;
	}
	return (max);
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

void	*ft_charmatrix_free(void **elem)
{
	if (!elem)
		return (NULL);
	while (*elem)
		free(*elem);
	return (NULL);
}