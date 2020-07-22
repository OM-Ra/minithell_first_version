/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:48:39 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/05 11:48:41 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*write_name(char *args, size_t *i, int flag)
{
	char	buf[320001];
	char	*name;
	size_t	j;

	j = 0;
	name = NULL;
	if (!args)
		return (NULL);
	while (args[*i] && (args[*i] != '=' || flag))
		buf[j++] = args[(*i)++];
	buf[j] = '\0';
	if (j)
	{
		if (!(name = ft_strdup(buf)))
			return (NULL);
	}
	if (args[*i] == '=')
		(*i)++;
	if (!name)
		name = ft_strdup("");
	return (name);
}

static int	error_name(char *args)
{
	ft_putstr_fd("setenv: wrong name: ", 2);
	ft_putstr_fd(args, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

static int	chaeck_name(char *args)
{
	int		flag_equally;
	size_t	i;

	i = 0;
	flag_equally = 0;
	while (args && args[i])
	{
		if (args[i] == '=')
			flag_equally++;
		i++;
	}
	if (!flag_equally)
		return (error_name(args));
	return (flag_equally);
}

int			setenv_function(char **args)
{
	char	*name;
	char	*param;
	size_t	j;
	size_t	i_args;

	i_args = 1;
	while (args[i_args])
	{
		j = 0;
		while (args[i_args][j])
		{
			if (!chaeck_name(args[i_args]))
				break ;
			ft_spacepass(args[i_args], &j);
			name = write_name(args[i_args], &j, 0);
			param = write_name(args[i_args], &j, 1);
			setenv(name, param, 1);
			if (name)
				free(name);
			if (param)
				free(param);
		}
		i_args++;
	}
	return (0);
}
