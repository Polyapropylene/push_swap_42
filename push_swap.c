/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polechkagadukina <polechkagadukina@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 23:34:19 by wvenita           #+#    #+#             */
/*   Updated: 2022/03/28 18:23:35 by polechkagad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		sort_three(stacks);
	else if (stacks->count_a <= 5)
		sort_five(stacks);
	else
		big_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	new = (t_data *)malloc(sizeof(t_data));
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!new || !stacks)
		exit(1);
	make_null(stacks, new);
	if (validation(argc, argv))
	{
		array_separation(argc, argv, new);
		duplicate_check(new, stacks);
		if (is_sorted(new))
		{
			init_stack(new, stacks);
			sort(stacks);
			free_stack(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
