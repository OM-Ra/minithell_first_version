/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:21:14 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/19 12:21:17 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_dollar(char *line, size_t *i)
{
	char	buf[320000];
	size_t	j;

	j = 0;
	if (line[*i] == '=')
	{
		(*i)++;
		while (!((line[*i] >= 9 && line[*i] <= 13) || line[*i] == 32) &&
				line[*i])
			buf[j++] = line[(*i)++];
		buf[j] = '\0';
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(buf, 2);
		ft_putstr_fd(" not found\n", 2);
	}
	return (0);
}

static void	check_valid_hooks(char *line, size_t *i)
{
	int num_hooks;

	num_hooks = 0;
	while (line[*i])
	{
		if (line[*i] == '(')
		{
			(*i)++;
			num_hooks++;
		}
		else if (line[*i] == ')')
		{
			(*i)++;
			num_hooks--;
		}
		else
			(*i)++;
		if (!num_hooks)
			break ;
	}
}

static int	check_valid(char *line)
{
	size_t	i;
	int		flag;

	i = 0;
	while (line[i])
	{
		ft_spacepass(line, &i);
		flag = 0;
		while (!((line[i] >= 9 && line[i] <= 13) || line[i] == 32) && line[i])
		{
			if (line[i] == '=' && !((line[i - 1] >= 9 &&
					line[i - 1] <= 13) || line[i - 1] == 32))
				flag = 1;
			else if (line[i] == '=')
				break ;
			else if (line[i] == '(')
				check_valid_hooks(line, &i);
			i++;
		}
		if (!flag)
			return (error_dollar(line, &i));
	}
	return (1);
}

static int	check_dollar(char *line)
{
	size_t i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '$' && i == 0) ||
				(line[i] == '$' && line[i - 1] != '\\'))
			return (1);
		i++;
	}
	return (0);
}

int			dollar(char **line, t_dol **ldol, t_args **largs_nuw)
{
	if (!(*line))
		return (0);
	if (check_dollar(*line))
		dollar_change(line, ldol, largs_nuw);
	if (ft_strcmp((*largs_nuw)->args[0], "env") &&
			ft_strcmp((*largs_nuw)->args[0], "setenv") && check_valid(*line))
		dollar_write_value(*line, ldol);
	return (0);
}
