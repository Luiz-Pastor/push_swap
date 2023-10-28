/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:11:19 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/28 23:36:48 by marvin           ###   ########.fr       */
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

int	get_min_index(t_stack *head)
{
	int	min;
	int min_index;
	int iterate_index;

	min = *(int *)head->content;
	min_index = 0;
	iterate_index = 0;
	head = head->next;
	while (head != NULL)
	{
		if (*(int *)head->content < min)
		{
			min = *(int *)head->content;
			min_index = iterate_index;
		}
		head = head->next;
		iterate_index++;
	}
	return (min_index);
}

int	get_max_element(t_stack *head)
{
	int	max;

	max = *(int *)(head->content);
	head = head->next;
	while (head)
	{
		if (*(int *)(head->content) > max)
			max = *(int *)(head->content);
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

void	*ft_charmatrix_free(char **elem)
{
	char **head;

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
