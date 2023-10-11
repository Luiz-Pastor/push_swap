#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack {
	void			*content;
	struct s_stack	*next;
} t_stack;

t_stack	*ft_stacknew(void *content);
void	ft_stackclear(t_stack **lst, void (*del)(void*));
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stack_print(t_stack *stack, void (*print)(void*));

#endif