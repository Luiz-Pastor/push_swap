/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:12:47 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/27 09:16:36 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "../include/stack.h"

int	is_ordered(t_stack	*stack);
int	get_min_element(t_stack *head);
int	get_max_element(t_stack *head);
void	*int_copy(int elem);
void	*ft_charmatrix_free(void **elem);

#endif