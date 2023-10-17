/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:30:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/17 10:00:36 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/stack.h"
#include "../include/instructions.h"
#include "../include/order.h"
#include "../include/colores.h"
#include "../include/arguments.h"

void leaks(void)
{
	system("leaks -q push_swap");
}

void	int_print(void *elem)
{
	if (!elem)
		return ;
	printf("%d", *(int*)elem);
}


void test(t_stack **stack_a)
{
	t_stack	*stack_b = NULL;

	sa(stack_a);
	
	pb(stack_a, &stack_b);
	pb(stack_a, &stack_b);
	pb(stack_a, &stack_b);
	
	ra(stack_a);
	rb(&stack_b);
	
	rra(stack_a);
	rrb(&stack_b);
	
	sa(stack_a);
	
	pa(&stack_b, stack_a);
	pa(&stack_b, stack_a);
	pa(&stack_b, stack_a);

	ft_stack_print(*stack_a, int_print);
	printf("\n");
	ft_stack_print(stack_b, int_print);

	is_ordered(*stack_a) == 0 ? printf("No ordenada") : printf("Ordenada");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	//printf("> %d\n", argc);
	//atexit(leaks);
	if (argc < 2)
		return (1);
	stack = manage_arguments(argc, argv);
	if (!stack)
		return (printf("Error.\n"), 1);
	ft_stack_print(stack, int_print);
	//test(&stack);
	
	if (!is_ordered(stack))
		manage_order(&stack, argc - 1);

	ft_stackclear(&stack, free);
	return (0);
}
