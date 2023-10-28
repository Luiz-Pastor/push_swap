/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:44:30 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/28 19:59:42 by marvin           ###   ########.fr       */
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

int ss(t_stack **stack_a, t_stack **stack_b, int print);
int rr(t_stack **stack_a, t_stack **stack_b, int print);
int rrr(t_stack **stack_a, t_stack **stack_b, int print);

#endif