/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_ants_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:48:23 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/05 12:44:03 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void				go_ants_four(t_path_ants_list *result, t_var *var,
							int *ant)
{
	int					save;

	save = -1;
	while (result->path)
	{
		if (result->path->ant == -1)
		{
			result->path = result->path->next;
			continue ;
		}
		if (result->path->ant != -1)
		{
			if (save == -1 && var->ants >= *ant && result->mi2 > result->max)
			{
				result->mi2--;
				save = result->path->ant;
				result->path->ant = *ant;
				*ant += 1;
			}
			else
				ft_swap(&save, &result->path->ant);
		}
		result->path = result->path->next;
	}
}

void					print_ant(t_path_ants *path, int mi)
{
	t_path_ants			*head;
	t_path_ants			*save;
	int					x;
	int					wave;

	save = NULL;
	wave = mi;
	head = path;
	while (wave)
	{
		x = wave - 1;
		while (x--)
		{
			save = path;
			path = path->next;
		}
		if (path->ant > 0)
			ft_printf("L%d-%s", path->ant, path->name);
		if (save && save->ant > 0 && wave != 1 && path->ant > 0)
			write(1, " ", 1);
		wave--;
		path = head;
	}
}

static t_path_ants_list	*go_ants_three(t_path_ants_list *result_ants,
							t_var *var, int *ant, int *flag)
{
	t_path_ants			*ants_head;

	ants_head = result_ants->path;
	go_ants_four(result_ants, var, ant);
	result_ants->path = ants_head;
	while (result_ants->path)
	{
		if (result_ants->path->ant > 0)
			*flag += 1;
		result_ants->path = result_ants->path->next;
	}
	result_ants->path = ants_head;
	print_ant(result_ants->path, result_ants->max);
	result_ants = result_ants->next;
	return (result_ants);
}

static int				go_ants_two(t_path_ants_list *result_ants, int *ant,
							t_var *var)
{
	int					flag;

	flag = 0;
	while (result_ants)
	{
		if (result_ants->path->ant == 0 && var->ants >= *ant &&
				result_ants->mi2 > result_ants->max)
		{
			result_ants->mi2--;
			result_ants->path->ant = *ant;
			*ant += 1;
			if (result_ants->path->ant > 0)
			{
				flag += 1;
				ft_printf("L%d-%s", result_ants->path->ant,
					result_ants->path->name);
			}
			result_ants = result_ants->next;
			continue ;
		}
		result_ants = go_ants_three(result_ants, var, ant, &flag);
	}
	return (flag);
}

void					go_ants(t_path_ants_list *result_ants, t_var *var)
{
	int					last_ant;

	last_ant = 1;
	train(result_ants, var);
	while (1)
	{
		go_ants_two(result_ants, &last_ant, var);
		if (check_ants_out(result_ants))
			break ;
		write(1, "\n", 1);
	}
}
