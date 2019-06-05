/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 11:48:22 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/05 12:39:31 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char			*get_string(t_room *anthill, int index)
{
	while (anthill)
	{
		if (anthill->index == index)
			return (anthill->name);
		anthill = anthill->next;
	}
	return (NULL);
}

int				start_search(t_room *anthill)
{
	while (anthill)
	{
		if (anthill->start == 1)
			return (anthill->index);
		anthill = anthill->next;
	}
	return (-1);
}

int				end_search(t_room *anthill)
{
	while (anthill)
	{
		if (anthill->end == 1)
			return (anthill->index);
		anthill = anthill->next;
	}
	return (-1);
}

void			ft_error(int x)
{
	ft_printf("ERROR\n", x);
	exit(1);
}

void			ft_isinteger(char *str)
{
	int			i;
	long int	res;

	res = 0;
	i = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]))
			ft_error(2);
		res = res * 10 + (str[i] - '0');
		if (res < -2147483648 || res > 2147483647)
			ft_error(3);
		i++;
	}
}
