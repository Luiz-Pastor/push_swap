/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:30:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/28 23:37:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/stack.h"
#include "../include/instructions.h"
#include "../include/order.h"
#include "../include/arguments.h"
#include "../include/utils.h"

#define FD_ERROR 2

/* 
- Salida de errores: 2
*/

void	set_pos_val(t_stack *stack)
{
	const t_stack	*head = stack;
	t_stack *iterator;
	t_stack *smallest;
	int count;
	int min_content;
	
	count = 1;
	while (stack)
	{
		min_content = INT_MAX;
		iterator = (t_stack *)head;
		smallest = NULL;
		while (iterator)
		{
			if (iterator->pos_value == -1 && *(int *)iterator->content < min_content)
			{
				smallest = iterator;
				min_content = *(int *)iterator->content;
			}
			iterator = iterator->next;
		}
		if (smallest)
		{
			smallest->pos_value = count;
			count++;
		}
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
