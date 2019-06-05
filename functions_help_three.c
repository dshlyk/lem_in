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

void		check_startend(t_room *head)
{
	int		flag;
	int		flag2;

	flag = 0;
	flag2 = 0;
	while (head)
	{
		if (flag != 1)
			flag = (head->end == 1 ? 1 : 0);
		if (flag2 != 1)
			flag2 = (head->start == 1 ? 1 : 0);
		head = head->next;
	}
	if (flag2 != 1 || flag != 1)
	{
		ft_error(1);
		exit(0);
	}
}

int			check_pipes_two(t_room *anthill, char *str, char *str2)
{
	t_link	*head_link;

	if (!ft_strcmp(anthill->name, str))
	{
		head_link = anthill->link;
		while (anthill->link)
		{
			if (!ft_strcmp(anthill->link->room->name, str2))
			{
				anthill->link = head_link;
				return (1);
			}
			anthill->link = anthill->link->next;
		}
		anthill->link = head_link;
	}
	return (0);
}

int			check_pipes(t_room *anthill, char *str, char *str2)
{
	t_room	*head;

	head = anthill;
	while (head)
	{
		if (check_pipes_two(head, str, str2) ||
			check_pipes_two(head, str2, str))
			return (1);
		head = head->next;
	}
	return (0);
}

int			ft_strcmp_two(const char *s1, const char *s2)
{
	int		x;

	x = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[x] || s2[x])
	{
		if (s1[x] == 0 || s2[x] == 0)
			return (0);
		if (s1[x] != s2[x])
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return (0);
}
