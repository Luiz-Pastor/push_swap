/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:44:39 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/25 12:09:30 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_H
# define ORDER_H

# include "stack.h"

int		is_ordered(t_stack	*stack);
void	manage_order(t_stack **stack);

#endif