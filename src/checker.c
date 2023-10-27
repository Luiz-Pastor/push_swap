/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:32:48 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/27 08:43:01 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../include/order.h"
#include "../include/stack.h"
#include "../include/instructions.h"
#include "../include/arguments.h"
#include "../libft/libft.h"

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
	{
		sa(stack_a, 0);
		count += sb(stack_b, 0);
	}
	if (!strcmp(buffer, "rr\n"))
	{
		ra(stack_a, 0);
		count += rb(stack_b, 0);
	}
	if (!strcmp(buffer, "rrr\n"))
	{
		rra(stack_a, 0);
		count += rrb(stack_b, 0);
	}
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
			return (fprintf(stderr, "Error\n"));
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
		return (fprintf(stderr, "Error\n"), 1);
	stack_a = manage_arguments(argc, argv);
	if (!stack_a)
		return (fprintf(stderr, "Error\n"), 1);
	if (read_commands(&stack_a, &stack_b))
		return (1);
	if (ft_stacksize(stack_b) != 0)
		printf("KO\n");
	else if (!is_ordered(stack_a))
		printf("KO\n");
	else
		printf("OK\n");
	ft_stackclear(&stack_a, free);
	ft_stackclear(&stack_b, free);
	return (0);
}
