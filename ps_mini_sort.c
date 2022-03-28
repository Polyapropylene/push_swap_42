/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polechkagadukina <polechkagadukina@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:52:00 by wvenita           #+#    #+#             */
/*   Updated: 2022/03/28 18:02:06 by polechkagad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"  

static int	find_max(t_stack *s)
{
	int		max;

	max = s->data;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

void		sort_three(t_stacks *stacks)
{
	int		max;

	max = find_max(stacks->a);
	if (stacks->count_a == 1)
		return ;
	else if (stacks->count_a == 2)
	{
		if (stacks->a->data > stacks->a->next->data) 
			swap_a(stacks->a, 1);
		return ;
	}
	else if (stacks->count_a == 3)
	{
		if (stacks->a->data == max)
			rotate_a(&stacks->a, 1);
		if (stacks->a->next->data == max)
			reverse_rotate_a(&stacks->a, 1);
		if (stacks->a->data > stacks->a->next->data)
			swap_a(stacks->a, 1);
	}
}

void		sort_five(t_stacks *stacks)
{
	while (stacks->count_b < 2)
	{
		if (stacks->a->data == stacks->min || stacks->a->data == stacks->max)
			push_b(stacks, 1);
		else
			rotate_a(&stacks->a, 1);
	}
	sort_three(stacks);
	push_a(stacks, 1);
	push_a(stacks, 1);
	if (stacks->a->data == stacks->max)
	{
		rotate_a(&stacks->a, 1);
	}
	else
	{
		swap_a(stacks->a, 1);
		rotate_a(&stacks->a, 1);
	}
}
