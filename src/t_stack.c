/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:30:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/31 08:11:40 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stacknew(void *content)
{
	t_stack	*memory;

	memory = (t_stack *) malloc(sizeof(t_stack));
	if (!memory)
		return (NULL);
	memory->index = -1;
	memory->value = -1;
	memory->target = -1;
	memory->mv_sa = -1;
	memory->mv_sb = -1;
	memory->content = (int *)content;
	memory->next = NULL;
	memory->prev = NULL;
	return (memory);
}

void	ft_stackclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*current;
	t_stack	*aux;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		aux = current;
		current = current->next;
		if (del && aux->content)
			del(aux->content);
		free(aux);
	}
	*lst = NULL;
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!lst || !new)
		return ;
	current = *lst;
	if (!current)
	{
		*lst = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_stacksize(t_stack *lst)
{
	int		count;
	t_stack	*current;

	count = 0;
	if (!lst)
		return (0);
	current = lst;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
