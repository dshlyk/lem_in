/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:37:00 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/05 12:28:22 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			algoritm_three(t_room *anthill, t_room *anthill_head,
					t_path *path, t_var *var)
{
	t_link		*link_head;

	link_head = anthill->link;
	while (anthill->link)
	{
		if (anthill->link->room->price == 0 ||
				check_sidorovich(anthill_head, path->path[path->mi]))
		{
			if (anthill->link->room->visited == 0)
			{
				add_path(path, anthill->link->room->index);
				if (anthill->link->room->index != var->end)
					anthill->link->room->visited = 1;
				break ;
			}
		}
		else
			anthill->link->room->price--;
		anthill->link = anthill->link->next;
	}
	anthill->link = link_head;
}

t_path			*algoritm_five(t_path *path, t_var *var, t_room *anthill,
					t_room *anthill_head)
{
	t_link		*link_head;

	create_new_paths(path, var->links - 1);
	link_head = anthill->link;
	while (var->links)
	{
		if (algoritm_two(path, var, anthill, anthill_head))
			continue ;
		path = path->next;
	}
	anthill->link = link_head;
	return (path);
}

t_path			*algoritm_six(t_path *path, t_path **path_head)
{
	t_path		*save;

	save = path->next;
	*path_head = kill_path(path, *path_head);
	path = save;
	return (path);
}

t_room			*algoritm_seven(t_room *anthill, t_room *anthill_head,
					t_path *path)
{
	anthill = anthill_head;
	while (path->path[path->mi] != anthill->index)
		anthill = anthill->next;
	return (anthill);
}
