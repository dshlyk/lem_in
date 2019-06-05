/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:26:56 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 14:27:06 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "ft_printf.h"

typedef struct				s_input
{
	int						ants;
	int						step;
	int						count;
	char					*verts[10000];
	char					*coords[10000];
	char					*start;
	char					*end;
	char					*map;
	int						starts;
	int						ends;
}							t_input;

typedef struct				s_var
{
	int						ants;
	int						start;
	int						end;
	int						links;
	int						wave;
	int						the_end;
	int						prev;
	int						nast;
	int						flag;
	char					*map;
}							t_var;

typedef struct				s_path
{
	int						*path;
	int						mi;
	struct s_path			*next;
}							t_path;

typedef	struct				s_path_ants_list
{
	struct s_path_ants		*path;
	int						max;
	int						mi2;
	struct s_path_ants_list	*next;
}							t_path_ants_list;

typedef struct				s_path_ants
{
	char					*name;
	int						ant;
	struct s_path_ants		*next;
}							t_path_ants;

typedef struct				s_link
{
	struct s_room			*room;
	struct s_link			*next;
}							t_link;

typedef struct				s_room
{
	int						index;
	char					*name;
	struct s_link			*link;
	struct s_room			*next;
	short					visited;
	short					price;
	short					sidorovich;
	short					start;
	short					end;
}							t_room;

typedef struct				s_var_list
{
	t_path					*path;
	t_path					*path_head;
	t_path					*result;
	t_path					*result_prev;
	t_room					*anthill_head;
}							t_var_list;

typedef struct				s_type
{
	t_room					*head2;
	t_room					*temp;
	t_room					*temp2;
	t_link					*save;
	int						flag_str;
	int						flag_str2;
}							t_type;

void						init_verts(t_input *in, char **tmp);
/*
** algoritm
*/
void						algoritm(t_room *anthill, t_input *in);
void						algoritm_start(t_room *anthill, t_var *var);
int							algoritm_two(t_path *path, t_var *var,
								t_room *anthill, t_room *anthill_head);
void						algoritm_three(t_room *anthill,
								t_room *anthill_head, t_path *path, t_var *var);
t_path						*algoritm_four(t_path *path, t_room *anthill,
								t_var *var);
t_path						*algoritm_five(t_path *path, t_var *var,
								t_room *anthill, t_room *anthill_head);
t_path						*algoritm_six(t_path *path, t_path **path_head);
t_room						*algoritm_seven(t_room *anthill,
								t_room *anthill_head, t_path *path);
int							algoritm_nine(t_var *var, t_var_list *var_l);

/*
** functions_malloc
*/
t_room						*malloc_anthill();
t_link						*malloc_link();
t_path						*malloc_path(int start);
t_var						*malloc_var(int start, int end, char *map);
t_path_ants					*malloc_ants(char *name);
t_path_ants_list			*malloc_ants_list();
t_var_list					*malloc_var_l();
t_type						*malloc_type(t_room *head);

/*
** functions_add
*/
void						add_room(t_room *head, char *str);
t_path						*add_complete(t_path *path_head);
void						create_anthill(t_room *anthill, char **tmp);
void						add_link(t_room *head, char *str, char *str2);

/*
** functions_ants
*/
void						ants(t_path *result, t_room *anthill, t_var *var);
void						train(t_path_ants_list *result, t_var *var);
void						go_ants(t_path_ants_list *result_ants, t_var *var);

/*
** functions_check
*/
int							check_ant_start(t_var *var, t_path *result_prev,
								t_path *result, t_room *anthill_head);
int							check_final(t_path *result_head,
								t_room *anthill_head, t_var *var);
int							check_ants_out(t_path_ants_list *result_ants);
int							ch_mass(const int *mas1, const int *mas2,
								int mi1, int mi2);
int							check_end(t_path *path, int end);
int							check_links(t_link *link);
int							check_sidorovich(t_room *anthill_head, int index);
int							check_max_path_result(t_path *result);
void						check_double_room(char **verts);
void						check_correct_room(char **tmp, char **verts);
void						check_verts(char **tmp, t_input *in);
void						start_end(int fd, t_input *in, char *line);

/*
** functions_help
*/
char						*get_string(t_room *anthill, int index);
int							start_search(t_room *anthill);
int							end_search(t_room *anthill);
void						ft_error(int x);
void						ft_isinteger(char *str);
t_input						*malloc_in(void);
void						anthill_start_end(t_room *anthill, t_input *in);
void						save_map(t_input *in, char *line);
int							ft_strcmp_two(const char *s1, const char *s2);
int							check_pipes(t_room *anthill, char *str, char *str2);
void						check_startend(t_room *head);

/*
** functions_free
*/
void						free_mas(char **mas, int col);
void						free_anthill(t_room *anthill);
void						free_path(t_path *path);
void						free_ants_path_list(t_path_ants_list *list);
void						free_verts(char **mas);
void						free_in(t_input *in);

/*
** functions_path
*/
t_path						*kill_path(t_path *path, t_path *path_head);
void						add_path(t_path *path, int new);
int							*copy_path(const int *path, int mi);
void						create_new_paths(t_path *path, int links);
t_path						*create_all_path(t_path *result_head);

/*
** functions_restart
*/
int							restart(t_room *anthill_head, t_path *path_head,
								t_var *var);
t_path						*sort_result(t_path *result_head);

#endif
