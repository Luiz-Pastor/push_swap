/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:30:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/11 12:35:52 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/stack.h"
#include "../include/instructions.h"
#include "../include/order.h"
#include "../include/colores.h"

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

int	*int_copy(int number)
{
	int	*memory;

	memory = (int *)malloc(sizeof(int));
	if (!memory)
		return (NULL);
	*memory = number;
	return (memory);
}

t_stack	*check_arguments(int argc, char **argv)
{
	int	index;
	int *element;
	int	flag;
	t_stack	*head;
	t_stack	*node;

	index = 2;
	element = int_copy(ft_strict_atoi(argv[1], &flag));
	head = ft_stacknew(element);
	if (!head || !element)
		return (NULL);
	while (index < argc)
	{
		element = int_copy(ft_strict_atoi(argv[index], &flag));
		node = ft_stacknew(element);
		if (!node || !element)
			return (ft_stackclear(&head, free), NULL);
		ft_stackadd_back(&head, node);
		index++;
	}
	return (head);
}

int	is_ordered(t_stack	*stack)
{
	int	prev;
	int current;

	if (!stack)
		return (1);
	prev = *(int*)stack->content;
	stack = stack->next;
	while (stack)
	{
		current = *(int*)stack->content;
		if (prev > current)
			return (0);
		prev = current;
		stack = stack->next;
	}
	return (1);
}

void test(t_stack **stack_a)
{
	t_stack	*stack_b = NULL;

	s(stack_a, 'a');
	
	p(stack_a, &stack_b, 'b');
	p(stack_a, &stack_b, 'b');
	p(stack_a, &stack_b, 'b');
	
	r(stack_a, 'a');
	r(&stack_b, 'b');
	
	rr(stack_a, 'a');
	rr(&stack_b, 'b');
	
	s(stack_a, 'a');
	
	p(&stack_b, stack_a, 'a');
	p(&stack_b, stack_a, 'a');
	p(&stack_b, stack_a, 'a');

	ft_stack_print(*stack_a, int_print);
	printf("\n");
	ft_stack_print(stack_b, int_print);

	is_ordered(*stack_a) == 0 ? printf("No ordenada") : printf("Ordenada");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	atexit(leaks);
	
	if (argc < 2)
		return (1);
	stack = check_arguments(argc, argv);
	if (!stack)
		return (printf("Error.\n"), 1);
	//ft_stack_print(stack, int_print);
	//test(&stack);

	printf("===================================\n");
	ft_stack_print(stack, int_print);
	printf("===================================");
	
	if (!is_ordered(stack))
		manage_order(&stack, argc - 1);

	printf("===================================\n");
	ft_stack_print(stack, int_print);
	printf("===================================\n");

	if (is_ordered(stack))
		printf("%sOrdenado%s\n", COLOR_LIGHTGREEN, COLOR_RESET);
	else
		printf("%sNo ordenado%s\n", COLOR_RED, COLOR_RESET);

	ft_stackclear(&stack, free);
	return (0);
}