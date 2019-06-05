/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:41:59 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/05 12:45:40 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_input			*malloc_in(void)
{
	t_input		*in;
	int			x;

	if (!(in = (t_input*)malloc(sizeof(t_input))))
		exit(0);
	in->ants = 0;
	in->step = 0;
	in->count = 0;
	in->start = NULL;
	in->end = NULL;
	in->map = NULL;
	in->starts = 0;
	in->ends = 0;
	x = 0;
	while (x++ < 10000)
	{
		in->verts[x] = NULL;
		in->coords[x] = NULL;
	}
	return (in);
}

void			anthill_start_end(t_room *anthill, t_input *in)
{
	t_room		*anthill_head;

	anthill_head = anthill;
	while (anthill_head)
	{
		if (!ft_strcmp(in->start, anthill_head->name))
		{
			anthill_head->start = 1;
			anthill_head->visited = 1;
		}
		if (!ft_strcmp(in->end, anthill_head->name))
			anthill_head->end = 1;
		anthill_head = anthill_head->next;
	}
}

void			save_map(t_input *in, char *line)
{
	char		*tmp;

	if (!in->map)
		in->map = ft_strdup(line);
	else
	{
		tmp = ft_strjoin(in->map, "\n");
		ft_memdel((void*)&in->map);
		in->map = ft_strjoin(tmp, line);
		ft_memdel((void*)&tmp);
	}
}

t_type			*malloc_type(t_room *head)
{
	t_type		*var;

	var = (t_type*)malloc(sizeof(t_type));
	var->flag_str = 1;
	var->flag_str2 = 1;
	var->temp = NULL;
	var->temp2 = NULL;
	var->save = NULL;
	var->head2 = head;
	return (var);
}
