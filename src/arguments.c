/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:25:42 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/27 09:16:46 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/arguments.h"
#include "../libft/libft.h"
#include "../include/utils.h"
#include <stdio.h>

int	add_arguments(char *str, t_stack **head)
{
	int		*element;
	t_stack	*node;
	int		flag;

	element = int_copy(ft_strict_atoi(str, &flag));
	node = ft_stacknew(element);
	if (!node || !element || flag < 0)
	{
		if (element)
			free(element);
		return (ft_stackclear(head, NULL), 1);
	}
	ft_stackadd_back(head, node);
	return (0);
}

static t_stack	*check_repeated(t_stack *head)
{
	t_stack	*node_current;
	t_stack	*node_cmp;

	if (!head)
		return (NULL);
	node_current = head;
	while (node_current)
	{
		node_cmp = node_current->next;
		while (node_cmp)
		{
			if (*(int *)node_current->content == *(int *) node_cmp->content)
			{
				ft_stackclear(&head, NULL);
				return (NULL);
			}
			node_cmp = node_cmp->next;
		}
		node_current = node_current->next;
	}
	return (head);
}

		/*element = int_copy(ft_strict_atoi(arguments[index], &flag));
		node = ft_stacknew(element);
		if (!node || !element || flag < 0)
		{
			if (element)
				free(element);
			return (ft_stackclear(&head, NULL), NULL);
		}
		ft_stackadd_back(&head, node);*/
static t_stack	*split_arguments(char *argv)
{
	int		*element;
	char	**arguments;
	int		flag;
	size_t	index;
	t_stack	*head;

	index = 0;
	arguments = ft_split(argv, ' ');
	if (!arguments || !arguments[0])
		return (ft_charmatrix_free((void **)arguments));
	element = int_copy(ft_strict_atoi(arguments[0], &flag));
	head = ft_stacknew(element);
	if (!head || !element || flag < 0)
	{
		if (element)
			free(element);
		return (ft_stackclear(&head, NULL), NULL);
	}
	while (arguments[++index])
	{
		if (add_arguments(arguments[index], &head))
			return (NULL);
	}
	return (check_repeated(head));
}

		/*element = int_copy(ft_strict_atoi(argv[index], &flag));
		node = ft_stacknew(element);
		if (!node || !element || flag < 0)
		{
			if (element)
				free(element);
			return (ft_stackclear(&head, NULL), NULL);
		}
		ft_stackadd_back(&head, node);*/
static t_stack	*get_stack(int argc, char **argv)
{
	int		index;
	int		*element;
	int		flag;
	t_stack	*head;

	index = 2;
	element = int_copy(ft_strict_atoi(argv[1], &flag));
	head = ft_stacknew(element);
	if (!head || !element || flag < 0)
	{
		if (element)
			free(element);
		return (ft_stackclear(&head, NULL), NULL);
	}
	while (index < argc)
	{
		if (add_arguments(argv[index], &head))
			return (NULL);
		index++;
	}
	return (check_repeated(head));
}

t_stack	*manage_arguments(int argc, char **argv)
{
	if (argc == 2)
		return (split_arguments(argv[1]));
	else
		return (get_stack(argc, argv));
}
