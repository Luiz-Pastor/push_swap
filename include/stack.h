#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack {
	size_t index;
	void	*content;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

t_stack	*ft_stack_create(void *content);
void	ft_stack_delete(t_stack **head, void (*delete)(void*));
void	ft_stack_updateindex(t_stack *head);
void	ft_stack_print(t_stack *stack, void (*print)(void*));
void	ft_stack_addfront(t_stack **stack, t_stack *node);
void	ft_stack_addback(t_stack **stack, t_stack *node);
t_stack	*ft_stack_popfront(t_stack **stack);
t_stack	*ft_stack_popback(t_stack **stack);

#endif