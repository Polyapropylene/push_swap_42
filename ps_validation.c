/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polechkagadukina <polechkagadukina@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:43:19 by wvenita           #+#    #+#             */
/*   Updated: 2022/03/28 18:30:43 by polechkagad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	search_duplicate(const int *dup, int count)
{
	int		i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			error_handler();
		i++;
	}
}

static void	number_availability(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	error_handler();
}

static void	valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				error_handler();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			error_handler();
		i++;
	}
}

void		duplicate_check(t_data *new, t_stacks *stacks)
{
	int		*dup;

	dup = (int *)malloc(sizeof(int) * (new->count_element));
	if (!dup)
		exit(1);
	dup = intarrcpy(dup, new->a, new->count_element);
	quick_sort(dup, 0, new->count_element - 1);
	search_duplicate(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}

int	validation(int argc, char **argv)
{
	int		i;
	int		ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (only_spaces(argv[i]))
		{
			number_availability(argv[i]);
			valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}
