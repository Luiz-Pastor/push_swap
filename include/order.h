/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:44:39 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/28 17:37:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_H
# define ORDER_H

# include "stack.h"

int		is_ordered(t_stack	*stack);
void	manage_order(t_stack **stack);

void	order3(t_stack **head);

#endif