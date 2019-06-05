/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_restart.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 08:06:46 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/26 08:06:52 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		restart_two(t_path *path_head, t_room *anthill_head)
{
	int			x;
	t_room		*anthill;

	while (path_head)
	{
		x = 0;
		while (x <= path_head->mi)
		{
			anthill = anthill_head;
			while (anthill && anthill->index != path_head->path[x])
				anthill = anthill->next;
			if (anthill && path_head->path[x] == anthill->index &&
					anthill->price != 1 && anthill->start != 1 &&
					anthill->end != 1)
			{
				anthill->price = 1;
				anthill->sidorovich = 1;
				x++;
			}
			else
				x++;
		}
		path_head = path_head->next;
	}
}

int				restart(t_room *anthill_head, t_path *path_head, t_var *var)
{
	t_room		*anthill;

	anthill = anthill_head;
	while (anthill)
	{
		anthill->price = 0;
		anthill->sidorovich = 0;
		if (anthill->index == var->start)
		{
			anthill->visited = 1;
			anthill->sidorovich = 1;
		}
		else
			anthill->visited = 0;
		anthill = anthill->next;
	}
	restart_two(path_head, anthill_head);
	return (0);
}
