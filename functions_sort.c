/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:49:44 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/31 10:49:47 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_sort_result(t_path *result)
{
	while (result)
	{
		if (result->next && result->mi > result->next->mi)
			return (1);
		result = result->next;
	}
	return (0);
}

static void	sort_result_two(t_path *result, t_path *save)
{
	t_path	*save2;

	while (result->next && result->mi <= result->next->mi)
	{
		save = result;
		result = result->next;
	}
	if (result->next && result->mi > result->next->mi)
	{
		save2 = result->next;
		save->next = save2;
		result->next = save2->next;
		save2->next = result;
	}
}

t_path		*sort_result(t_path *result_head)
{
	t_path	*result;
	t_path	*head;
	t_path	*save;

	result = result_head;
	head = result;
	while (check_sort_result(head))
	{
		if (result == head && result->mi > result->next->mi)
		{
			save = result->next;
			result->next = save->next;
			save->next = result;
			head = save;
		}
		result = head;
		save = head;
		sort_result_two(result, save);
		result = head;
	}
	return (head);
}
