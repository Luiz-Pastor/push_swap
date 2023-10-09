/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:30:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/09 12:32:14 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/stack.h"
#include "../include/instructions.h"

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

static int	*check_arguments(int argc, char **argv)
{
	int		*array;
	int		flag;
	int		index;
	int		check;

	index = 1;
	array = (int *) malloc((argc - 1) * sizeof(int));
	if (!array)
		return (NULL);
	while (index < argc)
	{
		array[index-1] = ft_strict_atoi(argv[index], &flag);
		if (flag < 0)
			return (free(array), NULL);
		check = 0;
		while (check < (index - 1))
		{
			if (array[check] == array[index - 1])
				return (free(array), NULL);
			check++;
		}
		index++;
	}
	return (array);
}

static t_stack	*get_stack(int *array, int max)
{
	t_stack	*head;
	t_stack	*current;
	int		index;

	index = 1;
	head = ft_stack_create(&array[0]);
	if (!head)
		return (NULL);
	current = head;
	while (index < max)
	{
		current->next = ft_stack_create(&array[index]);
		if (!current->next)
		{
			ft_stack_delete(&head, NULL);
			return (NULL);
		}
		current = current->next;
		index++;
	}
	return (head);	
}

static int	is_ordered(t_stack *head)
{
	int prev;
	int current;

	prev = *(int*)head->content;
	head = head->next;
	while (head)
	{
		current = *(int*)head->content;
		if (!current)
			return (0);
		if (prev > current)
			return (0);
		head = head->next;
		prev = current;
	}
	return (1);
}

void	test(t_stack *stack)
{
	sa
}

int	main(int argc, char *argv[])
{
	int		*array;
	t_stack	*stack;

	atexit(leaks);

	if (argc < 2)
		return (1);
	array = check_arguments(argc, argv);
	if (!array)
		return (printf("Error.\n"), 1);
	stack = get_stack(array, argc - 1);
	if (!stack)
		return (printf("Error con la stack :/\n"), 1);
	ft_stack_updateindex(stack);
	/*ft_stack_print(stack, int_print);
	if (!is_ordered(stack))
	{
		//manage_order(argc, stack);
		printf("No ordenaddo\n");
	}
	ft_stack_delete(&stack, NULL);
	free(array);*/
	test(stack);
	return (0);
}
