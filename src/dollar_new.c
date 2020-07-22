/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:53:12 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/19 12:53:14 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dol	*creat_dol(void)
{
	t_dol *newdol;

	if (!(newdol = (t_dol *)malloc(sizeof(t_dol))))
		return (NULL);
	newdol->i = 0;
	newdol->next = NULL;
	newdol->value = NULL;
	newdol->name = NULL;
	return (newdol);
}

t_dol			*dollar_new(t_dol **ldol)
{
	t_dol *newdol;
	t_dol *buf_dol;

	if (!(newdol = creat_dol()))
		return (NULL);
	if ((*ldol))
	{
		buf_dol = (*ldol);
		while (buf_dol->next)
			buf_dol = buf_dol->next;
		buf_dol->next = newdol;
		return (*ldol);
	}
	else
		return ((*ldol) = newdol);
}
