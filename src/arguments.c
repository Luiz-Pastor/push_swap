/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:25:42 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/17 11:11:47 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/arguments.h"
#include "../libft/libft.h"

int	*int_copy(int number)
{
	int	*memory;

	memory = (int *)malloc(sizeof(int));
	if (!memory)
		return (NULL);
	*memory = number;
	return (memory);
}

static t_stack	*split_arguments(char *argv)
{
	int		*element;
	char	**arguments;
	int		flag;
	size_t	index;
	t_stack	*head;
	t_stack	*node;

	index = 1;
	arguments = ft_split(argv, ' ');
	if (!arguments)
		return (NULL);
	element = int_copy(ft_strict_atoi(arguments[0], &flag));
	head = ft_stacknew(element);
	if (!head || !element || flag < 0)
	{
		if (element)
			free(element);
		return (ft_stackclear(&head, NULL), NULL);
	}
	while (argv[index])
	{
		element = int_copy(ft_strict_atoi(arguments[index], &flag));
		node = ft_stacknew(element);
		if (!node || !element || flag < 0)
		{
			if (element)
				free(element);
			return (ft_stackclear(&head, NULL), NULL);
		}
		ft_stackadd_back(&head, node);
		index++;
	}
	return (head);
}
static t_stack	*get_stack(int argc, char **argv)
{
	int	index;
	int *element;
	int	flag;
	t_stack	*head;
	t_stack	*node;

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
		element = int_copy(ft_strict_atoi(argv[index], &flag));
		node = ft_stacknew(element);
		if (!node || !element || flag < 0)
		{
			if (element)
				free(element);
			return (ft_stackclear(&head, NULL), NULL);
		}
		ft_stackadd_back(&head, node);
		index++;
	}
	return (head);
}

t_stack	*manage_arguments(int argc, char **argv)
{
	if (argc == 2)
		return (split_arguments(argv[1]));
	else
		return (get_stack(argc, argv));
}

/*t_stack	*check_arguments(int argc, char **argv)
{
	int	index;
	int *element;
	int	flag;
	t_stack	*head;
	t_stack	*node;

	index = 2;
	element = int_copy(ft_strict_atoi(argv[index], &flag));
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
}*/