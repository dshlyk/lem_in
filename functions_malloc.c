/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:41:53 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/19 08:41:55 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_var			*malloc_var(int start, int end, char *map)
{
	t_var		*var;

	if (!(var = (t_var*)malloc(sizeof(t_var))))
		exit(0);
	var->ants = 0;
	var->links = 0;
	var->wave = 0;
	var->the_end = 0;
	var->prev = 0;
	var->nast = 0;
	var->start = start;
	var->end = end;
	var->map = ft_strdup(map);
	return (var);
}

t_var_list		*malloc_var_l(void)
{
	t_var_list	*var;

	if (!(var = (t_var_list*)malloc(sizeof(t_var_list))))
		exit(0);
	var->path = NULL;
	var->path_head = NULL;
	var->result = NULL;
	var->result_prev = NULL;
	var->anthill_head = NULL;
	return (var);
}

t_room			*malloc_anthill(void)
{
	t_room		*anthill;
	static int	index = 0;

	if (!(anthill = (t_room*)malloc(sizeof(t_room))))
		exit(0);
	anthill->index = index;
	anthill->name = NULL;
	anthill->visited = 0;
	anthill->price = 0;
	anthill->sidorovich = 0;
	anthill->start = 0;
	anthill->end = 0;
	anthill->link = NULL;
	anthill->next = NULL;
	index++;
	return (anthill);
}

t_link			*malloc_link(void)
{
	t_link		*link;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	link->room = NULL;
	link->next = NULL;
	return (link);
}

t_path			*malloc_path(int start)
{
	t_path		*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		exit(0);
	if (start != -1)
	{
		if (!(path->path = (int*)malloc(sizeof(int) * 1)))
			exit(0);
		path->path[0] = start;
	}
	else
		path->path = NULL;
	path->mi = 0;
	path->next = NULL;
	return (path);
}
