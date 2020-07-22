/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_largs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:33:46 by mdelphia          #+#    #+#             */
/*   Updated: 2019/09/28 14:33:48 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_largs_args(t_args *buf)
{
	size_t	i;

	i = 0;
	while (buf->args[i])
		free(buf->args[i++]);
	free(buf->args);
}

t_args		*free_largs(t_args *largs)
{
	t_args *buf;

	while (largs)
	{
		buf = largs;
		largs = largs->right;
		if (buf->args)
			free_largs_args(buf);
		if (buf->line)
			free(buf->line);
		free(buf);
	}
	return (NULL);
}
