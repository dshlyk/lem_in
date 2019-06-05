/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:37:34 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/21 09:37:37 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			add_room(t_room *head, char *str)
{
	while (head->name)
	{
		if (!ft_strcmp(head->name, str))
			return ;
		if (!head->next)
			break ;
		head = head->next;
	}
	head->next = malloc_anthill();
	head->name = ft_strdup(str);
}

static t_path	*add_complete_two(t_path *path_head)
{
	t_path *head;

	head = malloc_path(-1);
	head->path = copy_path(path_head->path, path_head->mi);
	head->mi = path_head->mi;
	return (head);
}

t_path			*add_complete(t_path *path_head)
{
	t_path	*head;
	t_path	*result;
	int		flag;

	head = add_complete_two(path_head);
	result = head;
	path_head = path_head->next;
	while (path_head)
	{
		head = result;
		flag = 0;
		while (head)
		{
			if (ch_mass(head->path, path_head->path, head->mi, path_head->mi))
				flag = 1;
			head = head->next;
		}
		head = result;
		while (head->next)
			head = head->next;
		if (flag == 0)
			head->next = add_complete_two(path_head);
		path_head = path_head->next;
	}
	return (result);
}

void			create_anthill(t_room *anthill, char **tmp)
{
	add_room(anthill, tmp[0]);
	add_room(anthill, tmp[1]);
	add_link(anthill, tmp[0], tmp[1]);
}
