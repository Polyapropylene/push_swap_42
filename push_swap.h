/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polechkagadukina <polechkagadukina@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:43:48 by wvenita           #+#    #+#             */
/*   Updated: 2022/03/28 19:13:52 by polechkagad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct		s_data
{
	int				a[10000];
	int				count_element;
}					t_data;

typedef struct		s_stack
{
	int				data;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	int				count_a;
	int				count_b;
	int				min;
	int				max;
	int				med;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

size_t	ft_strlen(const char *c);
void	ft_putstr(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	error_handler(void);
char	**ft_split(char const *s, char c);
int		count_w(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		only_spaces(const char *str);
int		is_sorted(t_data *new);
int		validation(int ac, char **av);
void	duplicate_check(t_data *new, t_stacks *stacks);
void	array_separation(int ac, char **av, t_data *new);
void	stacking(t_data *new, int *buff, int count);
void	init_stack(t_data *new, t_stacks *stacks);
void	free_stack(t_stacks *stacks);
void	make_null(t_stacks *stacks, t_data *new);
void	sort_three(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
void	quick_sort(int *array, int start, int end);
int		partition(int *array, int start, int end);
void	big_sort(t_stacks *stacks);
int		finding_place(t_stacks *s, t_stack *b,
					t_steps *steps, int min);
int		count_to_min(t_stack *a, int min);

void	rotate_a(t_stack **a, int i);
void	rotate_b(t_stack **b, int i);
void	rotate_r(t_stacks *s, int i);
void	reverse_rotate_a(t_stack **a, int i);
void	reverse_rotate_b(t_stack **b, int i);
void	reverse_rotate_r(t_stacks *s, int i);
void	swap_a(t_stack *a, int i);
void	swap_b(t_stack *a, int i);
void	swap_s(t_stacks *s, int i);
void	push_a(t_stacks *s, int i);
void	push_b(t_stacks *s, int i);

int		*intarrcpy(int *dst, const int *src, int count);

#endif
