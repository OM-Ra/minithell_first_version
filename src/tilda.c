/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:41:39 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/02 14:41:44 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	num_tilda(char **line)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '~' && (*line)[i - 1] != '\\')
			num++;
		i++;
	}
	return (num);
}

static void	write_line_tilda(char **line, char *buf, char *til, size_t len)
{
	size_t	i_buf;
	size_t	i;

	i = 0;
	i_buf = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '~' && (*line)[i - 1] != '\\')
		{
			ft_strcat(buf, til);
			i_buf += len;
		}
		else
			buf[i_buf++] = (*line)[i];
		i++;
	}
}

static int	change_tilda(char **line)
{
	char	*buf;
	char	*til;
	size_t	len;

	til = getenv("HOME");
	len = ft_strlen(til);
	if (!(buf = (char *)malloc(sizeof(char) * (ft_strlen(*line) +
			len * num_tilda(line) + 1))))
		return (1);
	write_line_tilda(line, buf, til, len);
	free(*line);
	(*line) = buf;
	return (0);
}

int			tilda(char **line)
{
	size_t	i;

	i = 0;
	while ((*line) && (*line)[i])
	{
		if ((*line)[i] == '~' && (*line)[i - 1] != '\\')
		{
			if (change_tilda(line))
				return (1);
			else
				break ;
		}
		i++;
	}
	return (0);
}
