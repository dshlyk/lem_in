/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_malloc_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:42:22 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/31 14:42:25 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path_ants			*malloc_ants(char *name)
{
	t_path_ants			*ants;

	if (!(ants = (t_path_ants*)malloc(sizeof(t_path_ants))))
		exit(0);
	ants->name = ft_strdup(name);
	ants->ant = 0;
	ants->next = NULL;
	return (ants);
}

t_path_ants_list	*malloc_ants_list(void)
{
	t_path_ants_list	*list;

	if (!(list = (t_path_ants_list*)malloc(sizeof(t_path_ants_list))))
		exit(0);
	list->path = NULL;
	list->max = 0;
	list->next = NULL;
	return (list);
}

void				free_mas(char **mas, int col)
{
	int					y;

	if (!mas)
		return ;
	y = 0;
	while (y <= col)
	{
		ft_memdel((void*)&mas[y]);
		y++;
	}
	ft_memdel((void*)&mas);
}

void				free_path(t_path *path)
{
	t_path				*save;

	if (!path)
		return ;
	save = path;
	while (save->next)
	{
		while (path->next->next)
			path = path->next;
		ft_memdel((void*)&path->next->path);
		ft_memdel((void*)&path->next);
		path = save;
	}
	ft_memdel((void*)&path->next);
	ft_memdel((void*)&path->path);
	ft_memdel((void*)&path);
}

void				free_in(t_input *in)
{
	ft_memdel((void*)&in->start);
	ft_memdel((void*)&in->end);
	ft_memdel((void*)&in->map);
	free_verts(in->verts);
	free_verts(in->coords);
	ft_memdel((void*)&in);
}
