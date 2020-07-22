/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largs_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:42:25 by mdelphia          #+#    #+#             */
/*   Updated: 2019/09/28 13:42:29 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_args	*new_list_args(t_args *largs)
{
	t_args *largsnew;

	if (!(largsnew = (t_args *)malloc(sizeof(t_args))))
		return (free_largs(largs));
	largsnew->args = NULL;
	largsnew->line = NULL;
	largsnew->flag = 0;
	largsnew->run_cmd = 1;
	largsnew->status = 0;
	largsnew->pid = 0;
	largsnew->flag_dol_variable = 0;
	largsnew->right = NULL;
	largsnew->left = NULL;
	return (largsnew);
}

t_args			*largs_new(t_args *largs)
{
	t_args *largsnew;
	t_args *buf;

	if (!(largsnew = new_list_args(largs)))
		return (NULL);
	if (!largs)
		return (largsnew);
	buf = largs;
	while (buf->right)
		buf = buf->right;
	buf->right = largsnew;
	largsnew->left = buf;
	largsnew->run_cmd = 0;
	return (largs);
}
