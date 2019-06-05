/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:25:39 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/28 12:25:44 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void				ants_two(t_path *result,
								t_path_ants_list *result_ants, t_room *anthill)
{
	t_path_ants			*ants_head;
	int					x;

	x = 1;
	result_ants->path = malloc_ants(get_string(anthill, result->path[1]));
	result_ants->max = result->mi;
	result_ants->mi2 = result_ants->max;
	ants_head = result_ants->path;
	while (x <= result->mi)
	{
		x++;
		result_ants->path->ant = 0;
		if (x > result->mi)
			break ;
		result_ants->path->next = malloc_ants(get_string(anthill,
			result->path[x]));
		result_ants->path = result_ants->path->next;
	}
	result_ants->path = ants_head;
}

void					ants(t_path *result, t_room *anthill, t_var *var)
{
	t_path_ants_list	*result_ants;
	t_path_ants_list	*result_ants_head;

	result_ants = NULL;
	result_ants_head = NULL;
	while (result)
	{
		if (result_ants == NULL)
		{
			result_ants = malloc_ants_list();
			result_ants_head = result_ants;
		}
		else
		{
			result_ants->next = malloc_ants_list();
			result_ants = result_ants->next;
		}
		ants_two(result, result_ants, anthill);
		result = result->next;
	}
	result_ants = result_ants_head;
	write(1, "\n", 1);
	go_ants(result_ants, var);
	free_ants_path_list(result_ants_head);
}

static t_path_ants_list	*train_two(t_path_ants_list *result,
							t_path_ants_list *result_head, int *save)
{
	t_path_ants_list	*temp;

	temp = result;
	if (temp->next)
		temp = temp->next;
	else
	{
		temp = result_head;
		if (temp->mi2 == *save)
			*save += 1;
	}
	return (temp);
}

void					train(t_path_ants_list *result, t_var *var)
{
	int					ants;
	int					save;
	t_path_ants_list	*result_head;

	ants = var->ants;
	result_head = result;
	save = result->mi2;
	while (ants > 0)
	{
		if (result->mi2 < save)
		{
			ants--;
			result->mi2++;
		}
		else if (result->mi2 > save)
		{
			save++;
			result = result_head;
			continue ;
		}
		result = train_two(result, result_head, &save);
	}
}
