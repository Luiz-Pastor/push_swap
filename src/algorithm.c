#include "../include/algorithm.h"
#include "../include/instructions.h"
#include "../include/utils.h"
#include "../include/order.h"
#include <limits.h>

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = ft_stacksize(*stack_a);
	pushes = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
	{
		if ((*stack_a)->pos_value <= stack_size / 2)
		{
			pb(stack_a, stack_b, 1);
			pushes++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
	while (stack_size - pushes > 3)
	{
		pb(stack_a, stack_b, 1);
		pushes++;
	}
}

void set_position(t_stack *stack)
{
	int index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
}

int get_target(t_stack **stack_a, int pos_value, int target_s, int target)
{
	t_stack *aux_stack;

	aux_stack = *stack_a;
	while (aux_stack)
	{
		if (aux_stack->pos_value > pos_value && aux_stack->pos_value < target_s)
		{
			target_s = aux_stack->pos_value;
			target = aux_stack->index;
		}
		aux_stack = aux_stack->next;
	}
	if (target_s != INT_MAX)
		return (target);
	aux_stack = *stack_a;
	while (aux_stack)
	{
		if (aux_stack->pos_value < target_s)
		{
			target_s = aux_stack->pos_value;
			target = aux_stack->index;
		}
		aux_stack = aux_stack->next;
	}
	return (target);
}

void get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	int objective;
	t_stack	*iterate_b;

	objective = 0;
	iterate_b = *stack_b;
	set_position(*stack_a);
	set_position(*stack_b);
	while (iterate_b)
	{
		objective = get_target(stack_a, iterate_b->pos_value, INT_MAX, objective);
		iterate_b->target = objective;
		iterate_b = iterate_b->next;
	}
}

void	check_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stacksize(tmp_a);
	size_b = ft_stacksize(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->index;
		if (tmp_b->index > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->index) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}


void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			cost_a++;
			cost_b++;
			rrr(stack_a, stack_b, 1);
		}
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			cost_a--;
			cost_b--;
			rr(stack_a, stack_b, 1);
		}
	}
	while (cost_a)
	{
		if (cost_a > 0)
		{
			ra(stack_a, 1);
			cost_a--;
		}
		else if (cost_a < 0)
		{
			rra(stack_a, 1);
			cost_a++;
		}
	}
	while (cost_b)
	{
		if (cost_b > 0)
		{
			rb(stack_b, 1);
			cost_b--;
		}
		else if (cost_b < 0)
		{
			rrb(stack_b, 1);
			cost_b++;
		}
	}
	pa(stack_b, stack_a, 1);
}

int ft_abs(int number)
{
	if (number < 0)
		return (number *= -1);
	return number;
}

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *aux_b;
	int best;
	int aux_cost_a;
	int aux_cost_b;

	aux_b = *stack_b;
	best = INT_MAX;
	while (aux_b)
	{
		if (ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_b) < best)
		{
			best = ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_b);
			aux_cost_a = aux_b->cost_a;
			aux_cost_b = aux_b->cost_b;
		}
		aux_b = aux_b->next;
	}
	do_move(stack_a, stack_b, aux_cost_a, aux_cost_b);
}

void	move_min(t_stack **stack)
{
	int length;
	int min_index;

	length = ft_stacksize(*stack);
	min_index = get_min_index(*stack);

	if (min_index < (length / 2))
	{
		while (!is_ordered(*stack))
			ra(stack, 1);
	}
	else
	{
		while (!is_ordered(*stack))
			rra(stack, 1);
	}
}

void	algorithm(t_stack **stack_a)
{
	t_stack *stack_b = NULL;

	push_init(stack_a, &stack_b);
	order3(stack_a);
	while (stack_b)
	{
	
		get_target_position(stack_a, &stack_b);
		check_cost(stack_a, &stack_b);
		cheapest_move(stack_a, &stack_b);
	}
	if (!is_ordered(*stack_a))
		move_min(stack_a);
}
