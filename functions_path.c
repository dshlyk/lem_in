/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:48:00 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/22 10:48:04 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path		*kill_path(t_path *path, t_path *path_head)
{
	t_path	*save;
	t_path	*save_head;

	if (path_head == path)
	{
		path_head = path_head->next;
		ft_memdel((void*)&path->path);
		path->next = NULL;
		ft_memdel((void*)&path);
		return (path_head);
	}
	save_head = path_head;
	while (path_head->next != path)
		path_head = path_head->next;
	save = path_head;
	path_head = path_head->next;
	save->next = path_head->next;
	ft_memdel((void*)&path_head->path);
	path_head->next = NULL;
	ft_memdel((void*)&path_head);
	return (save_head);
}

void		add_path(t_path *path, int new)
{
	int		*new_path;
	int		x;

	x = 0;
	new_path = (int*)malloc(sizeof(int) * (path->mi + 2));
	while (x <= path->mi)
	{
		new_path[x] = path->path[x];
		x++;
	}
	path->mi++;
	new_path[x] = new;
	free(path->path);
	path->path = new_path;
}

int			*copy_path(const int *path, int mi)
{
	int		*new;
	int		x;

	x = 0;
	new = (int*)malloc(sizeof(int) * (mi + 1));
	while (x <= mi)
	{
		new[x] = path[x];
		x++;
	}
	return (new);
}

void		create_new_paths(t_path *path, int links)
{
	t_path	*temp;
	t_path	*new;

	temp = path->next;
	while (links--)
	{
		new = malloc_path(0);
		ft_memdel((void*)&new->path);
		new->path = copy_path(path->path, path->mi);
		new->mi = path->mi;
		new->next = temp;
		path->next = new;
		path = path->next;
	}
}

t_path		*create_all_path(t_path *result_head)
{
	t_path	*result_prev;
	t_path	*result_prev_head;
	t_path	*result;

	result = result_head;
	result_prev = malloc_path(-1);
	result_prev->path = copy_path(result->path, result->mi);
	result_prev->mi = result->mi;
	result_prev_head = result_prev;
	while (result->next)
	{
		result_prev->next = malloc_path(-1);
		result_prev->next->path = copy_path(result->next->path,
			result->next->mi);
		result_prev->next->mi = result->next->mi;
		result = result->next;
		result_prev = result_prev->next;
	}
	return (result_prev_head);
}
