/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:36:10 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/22 10:36:12 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					check_ant_start(t_var *var, t_path *result_prev,
						t_path *result, t_room *anthill_head)
{
	t_path			*temp;

	temp = result;
	result = sort_result(temp);
	if (var->prev != 0 && var->prev == var->nast)
	{
		ft_printf("%s\n", var->map);
		ants(result_prev, anthill_head, var);
		free_path(result_prev);
		free_path(result);
		return (1);
	}
	if (check_final(result, anthill_head, var))
	{
		ft_printf("%s\n", var->map);
		ants(result, anthill_head, var);
		free_path(result);
		free_path(result_prev);
		return (1);
	}
	return (0);
}

int					check_final(t_path *result_head, t_room *anthill_head,
						t_var *var)
{
	t_room			*save;
	t_link			*link_head;

	save = anthill_head;
	var->links = 0;
	while (anthill_head)
	{
		if (anthill_head->index == var->start)
			break ;
		anthill_head = anthill_head->next;
	}
	anthill_head = save;
	link_head = anthill_head->link;
	while (anthill_head->link)
	{
		var->links++;
		anthill_head->link = anthill_head->link->next;
	}
	anthill_head->link = link_head;
	while (result_head)
	{
		var->links--;
		result_head = result_head->next;
	}
	return (var->links == 0 ? 1 : 0);
}

int					check_ants_out(t_path_ants_list *result_ants)
{
	t_path_ants		*save;

	while (result_ants)
	{
		save = result_ants->path;
		while (result_ants->path)
		{
			if (result_ants->path->ant != -1)
			{
				result_ants->path = save;
				return (0);
			}
			result_ants->path = result_ants->path->next;
		}
		result_ants->path = save;
		result_ants = result_ants->next;
	}
	return (1);
}

int					ch_mass(const int *mas1, const int *mas2, int mi1, int mi2)
{
	int				x;
	int				y;

	y = 1;
	while (y <= mi1 - 1)
	{
		x = 1;
		while (x <= mi2 - 1)
		{
			if (mas1[y] == mas2[x])
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
