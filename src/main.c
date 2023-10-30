/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:30:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/30 23:34:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_values(t_stack *node, int *count)
{
	if (node)
	{
		node->value = (*count);
		(*count)++;
	}
}

void	set_pos_val(t_stack *stack)
{
	const t_stack	*head = stack;
	t_stack			*iterator;
	t_stack			*smallest;
	int				count;
	int				min_content;

	count = 1;
	while (stack)
	{
		min_content = INT_MAX;
		iterator = (t_stack *)head;
		smallest = NULL;
		while (iterator)
		{
			if (iterator->value == -1 && *iterator->content < min_content)
			{
				smallest = iterator;
				min_content = *iterator->content;
			}
			iterator = iterator->next;
		}
		check_values(smallest, &count);
		stack = stack->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc < 2)
		return (write(FD_ERROR, "Error\n", 6));
	stack = manage_arguments(argc, argv);
	if (!stack)
		return (write(FD_ERROR, "Error\n", 6));
	set_pos_val(stack);
	if (!is_ordered(stack))
		manage_order(&stack);
	ft_stackclear(&stack, free);
	return (0);
}
