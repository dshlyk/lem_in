/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:41:59 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/05 12:38:03 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		count_ants(t_input *in, char *line)
{
	if (line[0] == '#')
	{
		save_map(in, line);
		return ;
	}
	ft_isinteger(line);
	in->ants = ft_atoi(line);
	if (in->ants <= 0)
		ft_error(6);
	in->step = 1;
	save_map(in, line);
}

void		init_verts(t_input *in, char **tmp)
{
	in->verts[in->count] = ft_strdup(tmp[0]);
	in->coords[in->count] = ft_strjoin(tmp[1], tmp[2]);
	in->count++;
	in->verts[in->count] = NULL;
	in->coords[in->count] = NULL;
	in->step = 2;
}

void		vertices(t_input *in, char *line, int fd)
{
	char	**tmp;

	if (line[0] == 'L')
		ft_error(7);
	else if (line[0] == '#')
	{
		save_map(in, line);
		if (ft_strequ(line, "##start"))
			start_end(fd, in, line);
		else if (ft_strequ(line, "##end"))
			start_end(fd, in, line);
		return ;
	}
	save_map(in, line);
	tmp = ft_strsplit(line, ' ');
	if (!tmp[1] || !tmp[2] || (ft_strlen(line) != ft_strlen(tmp[0]) +
		ft_strlen(tmp[1]) + ft_strlen(tmp[2]) + 2))
		ft_error(8);
	init_verts(in, tmp);
	check_verts(tmp, in);
	free_mas(tmp, 2);
}

void		edges(t_input *in, char *line, t_room *anthill)
{
	char	**tmp;

	if (line[0] == '#')
	{
		save_map(in, line);
		return ;
	}
	save_map(in, line);
	in->step = 3;
	tmp = ft_strsplit(line, '-');
	if (!ft_strcmp(tmp[0], tmp[1]) || check_pipes(anthill, tmp[0], tmp[1]))
		ft_error(101);
	if (!tmp[1] || tmp[2])
		ft_error(9);
	if (ft_strlen(line) != ft_strlen(tmp[0]) + ft_strlen(tmp[1]) + 1)
		ft_error(10);
	check_correct_room(tmp, in->verts);
	create_anthill(anthill, tmp);
	free_mas(tmp, 1);
}

int			main(void)
{
	int		fd;
	char	*line;
	t_room	*anthill;
	t_input	*in;

	anthill = malloc_anthill();
	fd = 0;
	in = malloc_in();
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0' || !ft_strcmp_two(line, "###"))
			ft_error(13);
		if (in->step == 0)
			count_ants(in, line);
		else if (in->step == 3 || ft_strchr(line, '-'))
			edges(in, line, anthill);
		else if (in->step == 1 || in->step == 2)
			vertices(in, line, fd);
		ft_memdel((void*)&line);
	}
	if (in->step != 3)
		ft_error(14);
	anthill_start_end(anthill, in);
	algoritm(anthill, in);
	return (0);
}
