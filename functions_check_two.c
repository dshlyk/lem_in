/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_check_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:25:40 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/31 15:25:41 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					check_end(t_path *path_head, int end)
{
	t_path			*path;

	path = path_head;
	while (path)
	{
		if (path->mi == 0)
			return (0);
		if (path->path[path->mi] != end)
			return (0);
		path = path->next;
	}
	return (1);
}

int					check_links(t_link *link)
{
	int				links;

	links = 0;
	while (link)
	{
		if (link->room->visited == 0)
			links++;
		link = link->next;
	}
	return (links);
}

int					check_sidorovich(t_room *anthill_head, int index)
{
	while (anthill_head)
	{
		if (anthill_head->index == index && anthill_head->sidorovich == 0)
			return (1);
		anthill_head = anthill_head->next;
	}
	return (0);
}

int					check_max_path_result(t_path *result)
{
	int				x;
	t_path			*path;

	path = result;
	x = 0;
	while (path)
	{
		x++;
		path = path->next;
	}
	return (x);
}
