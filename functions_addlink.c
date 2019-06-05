/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:41:59 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/05 12:44:10 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_link_two(t_room *head, char *str, char *str2, t_type *var)
{
	if (!ft_strcmp(head->name, str))
	{
		var->temp = head;
		var->save = head->link;
		while (head->link)
		{
			if (!ft_strcmp(head->link->room->name, str2))
				var->flag_str = 0;
			head->link = head->link->next;
		}
		head->link = var->save;
	}
}

void	add_link_two_two(t_room *head, char *str, char *str2, t_type *var)
{
	if (!ft_strcmp(head->name, str2))
	{
		var->temp2 = head;
		var->save = head->link;
		while (head->link)
		{
			if (!ft_strcmp(head->link->room->name, str))
				var->flag_str2 = 0;
			head->link = head->link->next;
		}
		head->link = var->save;
	}
}

void	add_link_three(t_room *head, char *str, t_type *var)
{
	if (!ft_strcmp(head->name, str) && var->flag_str)
	{
		if (head->link)
		{
			while (head->link->next)
				head->link = head->link->next;
			head->link->next = malloc_link();
			head->link->next->room = var->temp2;
		}
		else
		{
			head->link = malloc_link();
			head->link->room = var->temp2;
			var->save = head->link;
		}
		var->flag_str = 0;
	}
}

void	add_link_three_two(t_room *head, char *str2, t_type *var)
{
	if (!ft_strcmp(head->name, str2) && var->flag_str2)
	{
		if (head->link)
		{
			while (head->link->next)
				head->link = head->link->next;
			head->link->next = malloc_link();
			head->link->next->room = var->temp;
		}
		else
		{
			head->link = malloc_link();
			head->link->room = var->temp;
			var->save = head->link;
		}
		var->flag_str2 = 0;
	}
}

void	add_link(t_room *head, char *str, char *str2)
{
	t_type *var;

	var = malloc_type(head);
	while (head->name)
	{
		add_link_two(head, str, str2, var);
		add_link_two_two(head, str, str2, var);
		head = head->next;
	}
	head = var->head2;
	while (head && (var->flag_str || var->flag_str2))
	{
		if (head->link)
			var->save = head->link;
		add_link_three(head, str, var);
		add_link_three_two(head, str2, var);
		head->link = var->save;
		head = head->next;
	}
	ft_memdel((void*)&var);
}
