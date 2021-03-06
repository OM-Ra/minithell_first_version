/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_in_gnl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:23:49 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/29 12:23:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_fd_in_gnl(t_listgnl **start, int fd)
{
	if (*start && !fd)
	{
		free(*start);
		*start = NULL;
	}
}
