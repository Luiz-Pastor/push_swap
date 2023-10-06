/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:30:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/06 11:19:07 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void leaks(void)
{
	system("leaks -q push_swap");
}

void	ft_lstprint(t_list *lst, void (*f)(void*))
{
	size_t	count;

	if (!lst | !f)
		return ;
	count = 0;
	while (lst)
	{
		printf("(Node %zu): ", count);
		f(lst->content);
		printf("\n");
		lst = lst->next;
		count++;
	}
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

	index = 1;
	array = (int *) malloc((argc - 1) * sizeof(int));
	if (!array)
		return (NULL);
	while (index < argc)
	{
		array[index-1] = ft_strict_atoi(argv[index], &flag);
		if (flag < 0)
		{
			free(array);
			return (NULL);
		}
		index++;
	}
	return (array);
}

static t_list	*get_stack(int *array, int max)
{
	t_list	*head;
	t_list	*current;
	int		index;

	index = 1;
	head = ft_lstnew(&array[0]);
	if (!head)
		return (NULL);
	current = head;
	while (index < max)
	{
		current->next = ft_lstnew(&array[index]);
		if (!current->next)
		{
			ft_lstclear(&head, NULL);
			return (NULL);
		}
		current = current->next;
		index++;
	}
	return (head);	
}

int	main(int argc, char *argv[])
{
	int		*array;
	t_list	*stack;

	//atexit(leaks);

	if (argc < 2)
		return (1);
	array = check_arguments(argc, argv);
	if (!array)
		return (printf("Error de argumentos\n"), 1);
	
	printf("Array:\n");
	for (int i = 0; i < argc - 1; i++)
		printf("\t> %d (%d)\n", array[i], i);
	stack = get_stack(array, argc - 1);
	if (!stack)
		return (printf("Error con la stack :/\n"), 1);

	//ft_lstprint(stack, int_print);
	/*
		...
		Funciones de algoritmos
		...
	*/
	free(array);
	ft_lstclear(&stack, NULL);
	return (0);
}