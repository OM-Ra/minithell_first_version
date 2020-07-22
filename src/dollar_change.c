/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:42:26 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/19 14:42:28 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	creat_line(char **line, char new_line[920001])
{
	char *line_delete;

	line_delete = (*line);
	if (!((*line) = ft_strdup(new_line)))
		return (1);
	free(line_delete);
	return (0);
}

static void	write_name_var(char *name_var, char *line, size_t *i)
{
	size_t j;

	j = 0;
	if (line[*i] == '$')
		(*i)++;
	while (((line[*i] >= 'A' && line[*i] <= 'Z') || (line[*i] >= 'a' &&
	line[*i] <= 'z') || (line[*i] >= '0' && line[*i] <= '9') ||
	(line[*i] == '$' || line[*i] == '!')) && line[*i])
	{
		name_var[j++] = line[(*i)++];
		if (j == 1023)
		{
			name_var[j] = '\0';
			ft_putstr_fd("name variable $: ", 2);
			ft_putstr_fd(name_var, 2);
			ft_putchar_fd('\n', 2);
			break ;
		}
	}
	name_var[j] = '\0';
}

int			dollar_change(char **line, t_dol **ldol, t_args **largs_nuw)
{
	size_t	i;
	size_t	j;
	char	new_line[920001];
	char	name_var[1024];

	i = 0;
	j = 0;
	while ((*line)[i])
	{
		if (((*line)[i] == '$' && i == 0) ||
				((*line)[i] == '$' && ((*line)[i - 1] != '\\')))
		{
			new_line[j] = '\0';
			write_name_var(name_var, *line, &i);
			if (dollar_find_dollar(new_line, name_var, ldol, largs_nuw))
				ft_move_str_index(new_line, &j);
		}
		else
			new_line[j++] = (*line)[i++];
	}
	new_line[j] = '\0';
	if (creat_line(line, new_line))
		return (1);
	return (0);
}
