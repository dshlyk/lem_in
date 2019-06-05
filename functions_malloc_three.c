/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 08:45:32 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/22 08:45:40 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		free_link(t_link *link)
{
	t_link				*save;

	if (!link)
		return ;
	save = link;
	while (link->next)
	{
		while (link->next->next)
			link = link->next;
		link->next->room = NULL;
		ft_memdel((void*)&link->next);
		link = save;
	}
	link->room = NULL;
}

void			free_anthill(t_room *anthill)
{
	t_room				*save;

	save = anthill;
	while (save->next)
	{
		while (anthill->next->next)
			anthill = anthill->next;
		free_link(anthill->next->link);
		ft_memdel((void*)&anthill->next->link);
		ft_memdel((void*)&anthill->next->name);
		ft_memdel((void*)&anthill->next);
		anthill = save;
	}
	ft_memdel((void*)&anthill->name);
	free_link(anthill->link);
	ft_memdel((void*)&anthill->link);
	ft_memdel((void*)&anthill);
}

static void		free_ants_path(t_path_ants *path)
{
	t_path_ants			*head;

	if (!path)
		return ;
	head = path;
	while (head->next)
	{
		while (path->next->next)
			path = path->next;
		ft_memdel((void*)&path->next->name);
		ft_memdel((void*)&path->next);
		path = head;
	}
	ft_memdel((void*)&path->next->name);
	ft_memdel((void*)&path->next);
	ft_memdel((void*)&path->name);
}

void			free_ants_path_list(t_path_ants_list *list)
{
	t_path_ants_list	*head;

	if (!list)
		return ;
	head = list;
	while (list->next)
	{
		while (list->next->next)
			list = list->next;
		free_ants_path(list->next->path);
		ft_memdel((void*)&list->next->path);
		ft_memdel((void*)&list->next);
		list = head;
	}
	free_ants_path(list->path);
	ft_memdel((void*)&list->next);
	ft_memdel((void*)&list->path);
	ft_memdel((void*)&list);
}

void			free_verts(char **mas)
{
	int i;

	if (!mas)
		return ;
	i = 0;
	while (i < 10000)
	{
		if (mas[i])
			ft_memdel((void*)&mas[i]);
		else
			return ;
		i++;
	}
}
