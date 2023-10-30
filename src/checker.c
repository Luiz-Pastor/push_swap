/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:32:48 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/30 23:41:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <string.h>

int	instr_a(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	if (!strcmp(buffer, "sa\n"))
		return (sa(stack_a, 0));
	if (!strcmp(buffer, "pa\n"))
		return (pa(stack_b, stack_a, 0));
	if (!strcmp(buffer, "ra\n"))
		return (ra(stack_a, 0));
	if (!strcmp(buffer, "rra\n"))
		return (rra(stack_a, 0));
	return (0);
}

int	instr_b(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	if (!strcmp(buffer, "sb\n"))
		return (sb(stack_b, 0));
	if (!strcmp(buffer, "pb\n"))
		return (pb(stack_a, stack_b, 0));
	if (!strcmp(buffer, "rb\n"))
		return (rb(stack_b, 0));
	if (!strcmp(buffer, "rrb\n"))
		return (rrb(stack_b, 0));
	return (0);
}

int	do_instructions(char *buffer, t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = 0;
	count += instr_a(buffer, stack_a, stack_b);
	count += instr_b(buffer, stack_a, stack_b);
	if (!strcmp(buffer, "ss\n"))
		count += ss(stack_a, stack_b, 0);
	if (!strcmp(buffer, "rr\n"))
		count += rr(stack_a, stack_b, 0);
	if (!strcmp(buffer, "rrr\n"))
		count += rrr(stack_a, stack_b, 0);
	return (count);
}

int	read_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(0);
		if (!buffer)
			break ;
		if (do_instructions(buffer, stack_a, stack_b) != 1)
		{
			free(buffer);
			ft_stackclear(stack_a, free);
			ft_stackclear(stack_b, free);
			return (write(2, "Error\n", 6));
		}
		free(buffer);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (write(FD_ERROR, "Error\n", 6));
	stack_a = manage_arguments(argc, argv);
	if (!stack_a)
		return (write(2, "Error\n", 6));
	stack_b = NULL;
	if (read_commands(&stack_a, &stack_b))
		return (1);
	if (ft_stacksize(stack_b) != 0)
		write(1, "KO\n", 3);
	else if (!is_ordered(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_stackclear(&stack_a, free);
	ft_stackclear(&stack_b, free);
	return (0);
}
