/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:31:49 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/05 12:45:46 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				algoritm_two(t_path *path, t_var *var, t_room *anthill,
					t_room *anthill_head)
{
	if (anthill->link->room->price == 0 ||
		check_sidorovich(anthill_head, path->path[path->mi]))
	{
		if (anthill->link->room->visited != 0)
		{
			anthill->link = anthill->link->next;
			return (1);
		}
		add_path(path, anthill->link->room->index);
		if (anthill->link->room->index != var->end)
			anthill->link->room->visited = 1;
	}
	else
		anthill->link->room->price--;
	anthill->link = anthill->link->next;
	var->links--;
	return (0);
}

t_path			*algoritm_four(t_path *path, t_room *anthill, t_var *var)
{
	t_path		*path_head;
	t_room		*anthill_head;

	path_head = path;
	anthill_head = anthill;
	while (path)
	{
		while (path && path->path[path->mi] == var->end)
			path = path->next;
		if (!path)
			break ;
		anthill = algoritm_seven(anthill, anthill_head, path);
		if ((var->links = check_links(anthill->link)) > 1)
		{
			path = algoritm_five(path, var, anthill, anthill_head);
			continue ;
		}
		else if (var->links == 1)
			algoritm_three(anthill, anthill_head, path, var);
		else if (path->path[path->mi] != var->end)
			path = algoritm_six(path, &path_head);
		if (path)
			path = path->next;
	}
	return (path_head);
}

int				algoritm_nine(t_var *var, t_var_list *var_l)
{
	t_path		*save;

	var->the_end++;
	save = var_l->path_head;
	var_l->path_head = sort_result(save);
	var_l->result = add_complete(var_l->path_head);
	save = var_l->result;
	var_l->result = save;
	restart(var_l->anthill_head, var_l->result, var);
	var->nast = check_max_path_result(var_l->result);
	if (check_ant_start(var, var_l->result_prev, var_l->result,
		var_l->anthill_head))
		return (1);
	if (var_l->result_prev)
		free_path(var_l->result_prev);
	var_l->result_prev = create_all_path(var_l->result);
	var->prev = var->nast;
	var_l->path = var_l->path_head;
	free_path(var_l->path);
	free_path(var_l->result);
	var_l->path = malloc_path(var->start);
	var_l->path_head = var_l->path;
	return (0);
}

void			algoritm_start(t_room *anthill, t_var *var)
{
	t_var_list	*var_l;

	var_l = malloc_var_l();
	var_l->result_prev = NULL;
	var_l->path = malloc_path(var->start);
	var_l->path_head = var_l->path;
	var_l->anthill_head = anthill;
	while (1)
	{
		var_l->path = var_l->path_head;
		var->wave++;
		var_l->path_head = algoritm_four(var_l->path, anthill, var);
		if (!var_l->path_head)
		{
			ft_printf("ERROR\n");
			exit(0);
		}
		if (check_end(var_l->path_head, var->end))
			if (algoritm_nine(var, var_l))
			{
				free_path(var_l->path_head);
				ft_memdel((void*)&var_l);
				return ;
			}
	}
}

void			algoritm(t_room *anthill, t_input *in)
{
	t_var		*var;
	t_room		*head;

	if (in->starts != 1 || in->ends != 1)
		ft_error(1);
	head = anthill;
	while (head->next->next)
		head = head->next;
	ft_memdel((void*)&head->next);
	head->next = NULL;
	head = anthill;
	check_startend(head);
	var = malloc_var(start_search(anthill), end_search(anthill), in->map);
	var->ants = in->ants;
	algoritm_start(anthill, var);
	ft_memdel((void*)&var->map);
	ft_memdel((void*)&var);
	free_anthill(anthill);
	free_in(in);
}
