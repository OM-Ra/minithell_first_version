/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:44:47 by mdelphia          #+#    #+#             */
/*   Updated: 2019/09/07 14:44:50 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

typedef struct		s_args
{
	char			**args;
	char			*line;
	int				flag;
	int				run_cmd;
	int				status;
	pid_t			pid;
	int				flag_dol_variable;
	struct s_args	*right;
	struct s_args	*left;
}					t_args;

typedef struct		s_envlist
{
	int				i;
	int				p_big;
	int				num_u;
	int				line_as;
	char			**dirname;
}					t_envlist;

typedef struct		s_dollar
{
	char			*name;
	char			*value;
	size_t			i;
	struct s_dollar	*next;
}					t_dol;

int					main(void);
void				minishell(t_args *largs);
t_args				*pars_args(t_args **largs, t_dol **ldol);
t_args				*largs_new(t_args *largs);
t_args				*free_largs(t_args *largs);
t_args				*mllc_args(t_args **largs);
t_args				*last_run_largs(t_args *largs);
int					tilda(char **line);
int					cd_function(char **args);
void				exit_function(t_args *largs, t_dol *ldol);
int					setenv_function(char **args);
int					unsetenv_function(char **args);
int					check_args(t_args *largs, t_args *largs_nuw, t_dol *ldol);
int					write_shell(void);
int					env_funtion(t_args *largs_nuw);
int					check_norm_envlist(t_envlist *envlist, t_args *largs_nuw);
int					env_delet_environ(t_envlist *envlist, t_args *largs_nuw);
void				env_write_environ(t_args *largs_nuw);
void				env_find_executable_file(t_envlist *envlist,
						t_args *largs_nuw);
void				replacement_in_line(t_dol **ldol, t_args **largs_nuw);
int					dollar(char **line, t_dol **ldol, t_args **largs_nuw);
int					dollar_change(char **line, t_dol **ldol,
						t_args **largs_nuw);
t_dol				*dollar_new(t_dol **ldol);
void				dollar_write_env(char *name_variable,
						char *line, size_t *i);
void				dollar_write_new_dol(char *name_variable, char *line,
						size_t *i, t_dol **ldol);
void				dollar_write_str_value(char *value, char *line, size_t *i);
int					dollar_write_value(char *line, t_dol **ldol);
void				dollar_write_value_dol(t_dol *buf_dol,
						char *line, size_t *i);
int					dollar_special_symbols(char new_line[920001],
						char name_var[1024], t_args **largs_nuw);
int					echo_function(t_args *largs_nuw);
t_dol				*free_ldol(t_dol *ldol);
int					dollar_find_dollar(char new_line[920001],
						char name_var[1024], t_dol **ldol, t_args **largs_nuw);
int					go_exec(t_args *largs_nuw);

#endif
