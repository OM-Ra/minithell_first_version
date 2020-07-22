/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mllc_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:54:30 by mdelphia          #+#    #+#             */
/*   Updated: 2019/09/28 14:54:32 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_args	*last_largs(t_args *largs)
{
	t_args *largs_last;

	largs_last = largs;
	while (largs_last && largs_last->right)
		largs_last = largs_last->right;
	return (largs_last);
}

static void		true_line(char *line, size_t *i, int *num)
{
	while (line[*i] && (line[*i] != ';' ||
			(line[*i] == ';' && line[(*i) - 1] == '\\')))
	{
		if (line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\v')
			(*num)++;
		(*i)++;
	}
}

static int		num_args(t_args *largs, t_args *largs_nuw,
					char *line, size_t *i)
{
	int		num;
	char	*buf;
	size_t	start;

	num = 1;
	ft_spacepass(line, i);
	start = (*i);
	true_line(line, i, &num);
	if (!(buf = (char *)malloc(sizeof(char) * ((*i) - start + 1))))
	{
		free_largs(largs);
		return (0);
	}
	ft_strncpy(buf, &line[start], ((*i) - start));
	buf[((*i) - start)] = '\0';
	largs_nuw->line = buf;
	if (line[*i] == ';' || start)
		largs_nuw->flag = 1;
	if (line[*i])
		(*i)++;
	return (num);
}

static t_args	*error_length_line(void)
{
	ft_putstr_fd("minishell: string is big\n", 2);
	ft_putstr_fd("           [320,000 characters]\n", 2);
	return (NULL);
}

t_args			*mllc_args(t_args **largs)
{
	int		num;
	char	*line;
	t_args	*largs_nuw;
	size_t	i;

	i = 0;
	num = 0;
	line = NULL;
	get_next_line(0, &line);
	if (ft_strlen(line) > 320000)
		return (error_length_line());
	while (line[i])
	{
		if (!largs_new(*largs))
			return (NULL);
		largs_nuw = last_largs(*largs);
		num = num_args(*largs, largs_nuw, line, &i);
		if (!(largs_nuw->args = (char **)malloc(sizeof(char *) * (num + 1))))
			return (free_largs(*largs));
	}
	if (line)
		free(line);
	return (*largs);
}
