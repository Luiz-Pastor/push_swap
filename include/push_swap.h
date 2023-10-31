/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:06:30 by lpastor-          #+#    #+#             */
/*   Updated: 2023/10/31 08:15:38 by lpastor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define BUFFER_SIZE 50
# define FD_ERROR 2

typedef struct s_stack {
	int				index;
	int				value;
	int				target;
	int				mv_sa;
	int				mv_sb;

	int				*content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_stacknew(void *content);
void	ft_stackclear(t_stack **lst, void (*del)(void*));
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);
void	ft_stack_print(t_stack *stack, void (*print)(void*));

int		is_ordered(t_stack	*stack);
int		get_min_element(t_stack *head);
int		get_min_index(t_stack *head);
int		get_max_element(t_stack *head);
void	*int_copy(int elem);
void	*ft_matrix_free(char **elem);
void	int_print(void *elem);

int		is_ordered(t_stack	*stack);
void	manage_order(t_stack **stack);
void	order3(t_stack **head);
void	algorithm(t_stack **stack_a);

int		sa(t_stack **stack_a, int print);
int		pa(t_stack **stack_b, t_stack **stack_a, int print);
int		ra(t_stack **stack_a, int print);
int		rra(t_stack **stack_a, int print);

int		sb(t_stack **stack_b, int print);
int		pb(t_stack **stack_a, t_stack **stack_b, int print);
int		rb(t_stack **stack_b, int print);
int		rrb(t_stack **stack_b, int print);

int		ss(t_stack **stack_a, t_stack **stack_b, int print);
int		rr(t_stack **stack_a, t_stack **stack_b, int print);
int		rrr(t_stack **stack_a, t_stack **stack_b, int print);

t_stack	*manage_arguments(int argc, char **argv);

char	**ft_split(char const *s, char c);
int		ft_strict_atoi(const char *str, int *flag);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_abs(int number);

size_t	gnl_strlen(char *str);
char	*gnl_cpy(char *data);
int		gnl_find_ch(char *data, char ch);
void	*gnl_free(void **memory);
char	*add_line(char *data, char *add);
char	*get_next_line(int fd);

void	get_target_position(t_stack **stack_a, t_stack **stack_b);
void	get_movements_cost(t_stack **stack_a, t_stack **stack_b);
void	best_move(t_stack **stack_a, t_stack **stack_b);

#endif