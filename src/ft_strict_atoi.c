/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strict_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:26:47 by lpastor-          #+#    #+#             */
/*   Updated: 2024/01/29 14:14:32 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	get_number(const char *str, size_t *index, int *flag)
{
	long	number;

	number = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		*flag = 1;
		number = (number * 10) + (str[*index] - '0');
		(*index)++;
	}
	return (number);
}

static int	is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	if (ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int	ft_strict_atoi(const char *str, int *flag)
{
	long		count;
	size_t		index;
	int			sign;
	int			changed;

	sign = 1;
	count = 0;
	index = 0;
	*flag = 0;
	changed = 0;
	while (is_space(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	count = get_number(str, &index, &changed);
	if (str[index] || changed == 0 || count > INT_MAX || -count < INT_MIN)
		*flag = -1;
	return (sign * count);
}
