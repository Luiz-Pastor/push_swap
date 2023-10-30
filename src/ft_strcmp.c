/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:29:50 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/30 09:34:17 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	return (s1[index] - s2[index]);
}
