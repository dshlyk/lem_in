/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_check_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:25:40 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/05 12:43:32 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		check_double_room(char **verts)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (verts[i + 1])
	{
		while (verts[j + 1])
		{
			if (j == i)
				j++;
			if (ft_strequ(verts[i], verts[j]))
				ft_error(4);
			j++;
		}
		j = 0;
		i++;
	}
}

void		check_correct_room(char **tmp, char **verts)
{
	int		i;
	int		checker;

	i = 0;
	checker = 0;
	check_double_room(verts);
	while (verts[i])
	{
		if (ft_strequ(verts[i], tmp[0]))
			checker++;
		if (ft_strequ(verts[i], tmp[1]))
			checker++;
		i++;
	}
	if (checker != 2)
		ft_error(5);
}

void		check_verts(char **tmp, t_input *in)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tmp[1] == NULL || tmp[2] == NULL || tmp[3])
		ft_error(11);
	ft_isinteger(tmp[1]);
	ft_isinteger(tmp[2]);
	while (in->coords[i + 1])
	{
		while (in->coords[j + 1])
		{
			if (j == i)
				j++;
			if (ft_strequ(in->coords[i], in->coords[j]))
				ft_error(15);
			j++;
		}
		j = 0;
		i++;
	}
}

void		start_end(int fd, t_input *in, char *line)
{
	char	**tmp;
	char	*t;
	char	*tmp2;

	t = ft_strdup(line);
	get_next_line(fd, &tmp2);
	if (tmp2[0] == '\0' || tmp2[0] == '#')
		ft_error(12);
	tmp = ft_strsplit(tmp2, ' ');
	if (ft_strequ(t, "##start"))
	{
		in->start = ft_strdup(tmp[0]);
		in->starts++;
	}
	else if (ft_strequ(t, "##end"))
	{
		in->end = ft_strdup(tmp[0]);
		in->ends++;
	}
	check_verts(tmp, in);
	init_verts(in, tmp);
	save_map(in, tmp2);
	free_mas(tmp, 2);
	ft_memdel((void*)&t);
	ft_memdel((void*)&tmp2);
}
