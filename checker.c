/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhyhorn <rrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:05:23 by rrhyhorn          #+#    #+#             */
/*   Updated: 2022/07/02 19:53:51 by rrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		action_processing(char *line, t_stacks *s)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		swap_a(s->a, 0);
	else if (ft_strncmp(line, "sb", 2) == 0)
		swap_b(s->b, 0);
	else if (ft_strncmp(line, "pa", 2) == 0)
		push_a(s, 0);
	else if (ft_strncmp(line, "pb", 2) == 0)
		push_b(s, 0);
	else if (ft_strncmp(line, "ra", 2) == 0)
		rotate_a(&s->a, 0);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rotate_b(&s->b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0)
		rotate_r(s, 0);
	else if (ft_strncmp(line, "rra", 3) == 0)
		reverse_rotate_a(&s->a, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		reverse_rotate_b(&s->b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		reverse_rotate_r(s, 0);
}

static void		read_action(t_stacks *s)
{
	char		*line;

	line = NULL;
	while (get_next_line(0))
	{
		action_processing(line, s);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}


static int		stack_sorted(t_stacks *s)
{
	int			i;
	int			buff;
	t_stack		*save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->data;
		s->a = s->a->next;
		if (buff > s->a->data)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
}

int				main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		exit(1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	make_null(stacks, new);
	if (validation(argc, argv))
	{
		array_separation(argc, argv, new);
		duplicate_check(new, stacks);
		init_stack(new, stacks);
		read_action(stacks);
		if ((stack_sorted(stacks)) && stacks->count_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(stacks);
	free(new);
	free(stacks);
	return (0);
}