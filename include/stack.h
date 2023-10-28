/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:45:13 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/28 19:24:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack {
	int				index;
	int				pos_value;
	int				target;
	int				cost_a;
	int				cost_b;

	void			*content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_stacknew(void *content);
void	ft_stackclear(t_stack **lst, void (*del)(void*));
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);
void	ft_stack_print(t_stack *stack, void (*print)(void*));

#endif