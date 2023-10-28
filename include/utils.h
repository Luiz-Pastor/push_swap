/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:12:47 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/28 23:22:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "../include/stack.h"

int	is_ordered(t_stack	*stack);
int	get_min_element(t_stack *head);
int	get_min_index(t_stack *head);
int	get_max_element(t_stack *head);
void	*int_copy(int elem);
void	*ft_charmatrix_free(char **elem);
void int_print(void *elem);

#endif