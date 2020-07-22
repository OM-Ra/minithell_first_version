/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:55:26 by mdelphia          #+#    #+#             */
/*   Updated: 2019/09/28 13:55:29 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	write_args(t_args *largs_nuw)
{
	size_t	i;
	size_t	i_args;
	size_t	j;
	char	*line;
	char	buf[320001];

	i = 0;
	line = largs_nuw->line;
	i_args = 0;
	while (line[i])
	{
		j = 0;
		largs_nuw->args[i_args] = NULL;
		ft_spacepass(line, &i);
		while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\v')
			buf[j++] = line[i++];
		buf[j] = '\0';
		if (j)
			largs_nuw->args[i_args] = ft_strdup(buf);
		if (line[i])
			i++;
		i_args++;
	}
	largs_nuw->args[i_args] = NULL;
	return (0);
}

t_args		*pars_args(t_args **largs, t_dol **ldol)
{
	t_args *largs_nuw;

	mllc_args(largs);
	largs_nuw = *largs;
	while (largs_nuw->right && !largs_nuw->flag)
		largs_nuw = largs_nuw->right;
	while (largs_nuw && largs_nuw->line)
	{
		if (write_args(largs_nuw))
			return (free_largs(*largs));
		replacement_in_line(ldol, &largs_nuw);
		largs_nuw->flag = 0;
		largs_nuw = largs_nuw->right;
	}
	return (*largs);
}
