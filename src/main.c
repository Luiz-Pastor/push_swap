/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:30:32 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/27 08:13:52 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/stack.h"
#include "../include/instructions.h"
#include "../include/order.h"
#include "../include/colores.h"
#include "../include/arguments.h"
#include "../include/utils.h"

/* 
- Salida de errores: 2
*/

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc < 2)
		return (fprintf(stdout, "Error\n"), 1);
	stack = manage_arguments(argc, argv);
	if (!stack)
		return (fprintf(stdout, "Error\n"), 1);
	if (!is_ordered(stack))
		manage_order(&stack);
	ft_stackclear(&stack, free);
	return (0);
}
