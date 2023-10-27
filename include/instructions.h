/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:44:30 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/24 10:44:32 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "stack.h"

int	sa(t_stack **stack_a, int print);
int	pa(t_stack **stack_b, t_stack **stack_a, int print);
int	ra(t_stack **stack_a, int print);
int	rra(t_stack **stack_a, int print);

int	sb(t_stack **stack_b, int print);
int	pb(t_stack **stack_a, t_stack **stack_b, int print);
int	rb(t_stack **stack_b, int print);
int	rrb(t_stack **stack_b, int print);

#endif