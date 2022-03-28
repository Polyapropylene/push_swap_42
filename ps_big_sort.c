/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhyhorn <rrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:59:31 by wvenita           #+#    #+#             */
/*   Updated: 2022/03/28 19:20:38 by rrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	steps_markup(t_stack *b, int count)
{
	int		i;
	int		iter;
	t_stack	*buff;

	i = -1;
	iter = count / 2;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

static void	minimum_insertion_steps(t_stacks *stacks, t_steps *steps)
{
	int		min_action;
	t_stack	*first_a;
	t_stack	*first_b;

	min_action = -1;
	first_a = stacks->a;
	first_b = stacks->b;
	while (stacks->b)
	{
		min_action = finding_place(stacks, stacks->b, steps, min_action);
		stacks->a = first_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = first_b;
}

static void	instruction_execution(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			rotate_a(&stacks->a, 1);
		else
			reverse_rotate_a(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			rotate_b(&stacks->b, 1);
		else
			reverse_rotate_b(&stacks->b, 1);
		steps->count_b--;
	}
	push_a(stacks, 1);
}

static void	start_sort(t_stacks *stacks)
{
	t_steps *step;

	step = (t_steps *)malloc(sizeof(t_steps));
	if (!step)
		exit(1);
	while (stacks->count_b != 0)
	{
		step->count_a = -1;
		step->count_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		steps_markup(stacks->a, stacks->count_a);
		steps_markup(stacks->b, stacks->count_b);
		minimum_insertion_steps(stacks, step);
		instruction_execution(stacks, step);
	}
	if ((count_to_min(stacks->a, stacks->min)) > stacks->count_a / 2)
	{
		while (stacks->a->data != stacks->min)
			reverse_rotate_a(&stacks->a, 1);
	}
	else
		while (stacks->a->data != stacks->min)
			rotate_a(&stacks->a, 1);
	free(step);
}

void		big_sort(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max)
		{
			push_b(stacks, 1);
			if (stacks->b->data > stacks->med)
				rotate_b(&stacks->b, 1);
		}
		else
			rotate_a(&stacks->a, 1);
	}
	if (stacks->a->data < stacks->a->next->data)
		swap_a(stacks->a, 1);
	push_a(stacks, 1);
	start_sort(stacks);
}
