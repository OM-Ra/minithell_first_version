/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_write_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:51:07 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/21 13:51:09 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_valid_variable(char *line, size_t *i)
{
	char	buf[320000];
	size_t	j;
	size_t	i_line;

	i_line = (*i);
	j = 0;
	if (((line[(*i) - 1] >= 9 && line[(*i) - 1] <= 13) ||
			line[(*i) - 1] == 32))
	{
		while (line[i_line] && !((line[(*i) - 1] >= 9 &&
				line[(*i) - 1] <= 13) || line[(*i) - 1] == 32))
			buf[j++] = line[i_line++];
		buf[j] = '\0';
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(buf, 2);
		ft_putstr_fd(" not found\n", 2);
		return (0);
	}
	return (1);
}

static void		write_name_variable(char *name_variable, char *line, size_t *i)
{
	size_t j;
	size_t i_line;

	j = 0;
	i_line = *i;
	while (i_line > 0 && !((line[i_line - 1] >= 9 && line[i_line - 1] <= 13) ||
				line[i_line - 1] == 32))
		i_line--;
	while (line[i_line] && i_line != *i)
	{
		name_variable[j++] = line[i_line++];
		if (j == 1023)
		{
			name_variable[j] = '\0';
			ft_putstr_fd("name variable: ", 2);
			ft_putstr_fd(name_variable, 2);
			ft_putchar_fd('\n', 2);
			break ;
		}
	}
	name_variable[j] = '\0';
}

static int		find_name_variable_env(char *name_variable)
{
	if (getenv(name_variable))
		return (1);
	return (0);
}

static t_dol	*find_name_variable_dol(char name_variable[1024], t_dol **ldol)
{
	t_dol *buf_dol;

	if (!(*ldol))
		return (NULL);
	buf_dol = *ldol;
	while (buf_dol)
	{
		if (!ft_strcmp(name_variable, buf_dol->name))
			return (buf_dol);
		buf_dol = buf_dol->next;
	}
	return (NULL);
}

int				dollar_write_value(char *line, t_dol **ldol)
{
	size_t	i;
	t_dol	*buf_dol;
	char	name_variable[1024];

	i = 0;
	while (line[i])
	{
		if (line[i] == '=' && i > 0 && (check_valid_variable(line, &i)))
		{
			write_name_variable(name_variable, line, &i);
			if (find_name_variable_env(name_variable))
				dollar_write_env(name_variable, line, &i);
			if ((buf_dol = find_name_variable_dol(name_variable, ldol)))
				dollar_write_value_dol(buf_dol, line, &i);
			else
				dollar_write_new_dol(name_variable, line, &i, ldol);
		}
		i++;
	}
	return (0);
}
