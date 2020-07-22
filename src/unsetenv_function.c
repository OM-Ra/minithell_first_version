/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:36:47 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/09 11:36:49 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		unsetenv_function(char **args)
{
	size_t	i;

	i = 1;
	while (args[i])
	{
		if (getenv(args[i]))
			unsetenv(args[i]);
		i++;
	}
	return (0);
}
