/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:58:01 by mdelphia          #+#    #+#             */
/*   Updated: 2019/10/09 15:58:03 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		write_shell(void)
{
	char *name;
	char *pwd_nuw;

	setenv("PS1", "21shool@root-> ", 1);
	setenv("LC_TERMINAL_VERSION", "2019.0", 1);
	setenv("TERM_PROGRAM_VERSION", getenv("LC_TERMINAL_VERSION"), 1);
	setenv("TERM_PROGRAM", "minishell", 1);
	setenv("LC_TERMINAL", "minishell", 1);
	unsetenv("SSH_AUTH_SOCK");
	unsetenv("Apple_PubSub_Socket_Render");
	if (!(pwd_nuw = getcwd(NULL, 32000)))
		return (1);
	if (!(name = ft_strjoin(pwd_nuw, "/minishell")))
		return (1);
	setenv("SHELL", name, 1);
	free(pwd_nuw);
	free(name);
	return (0);
}
