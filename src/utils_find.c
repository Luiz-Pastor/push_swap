#include "../include/push_swap.h"

int	get_min_element(t_stack *head)
{
	int	min;

	min = *head->content;
	head = head->next;
	while (head != NULL)
	{
		if (*head->content < min)
			min = *head->content;
		head = head->next;
	}
	return (min);
}

int	get_min_index(t_stack *head)
{
	int	min;
	int	min_index;
	int	iterate_index;

	min = *head->content;
	min_index = 0;
	iterate_index = 0;
	head = head->next;
	while (head != NULL)
	{
		if (*head->content < min)
		{
			min = *head->content;
			min_index = iterate_index;
		}
		head = head->next;
		iterate_index++;
	}
	return (min_index);
}

int	get_max_element(t_stack *head)
{
	int	max;

	max = *(head->content);
	head = head->next;
	while (head)
	{
		if (*(head->content) > max)
			max = *(head->content);
		head = head->next;
	}
	return (max);
}
