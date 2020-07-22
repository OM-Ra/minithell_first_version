/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:29:14 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/03 11:29:16 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_listgnl	*ft_lstgnlnew(const int fd, t_listgnl **start)
{
	t_listgnl			*list;

	if (!start)
	{
		if (!(list = (t_listgnl *)malloc(sizeof(t_listgnl))))
			return (NULL);
		list->fd_listgnl = fd;
		list->i = 0;
		list->next = NULL;
		return (list);
	}
	list = (t_listgnl *)(*start);
	while (list->next && fd != list->fd_listgnl)
		list = list->next;
	if (fd == list->fd_listgnl)
		return (list);
	if (!(list->next = (t_listgnl *)malloc(sizeof(t_listgnl))))
		return (NULL);
	list = list->next;
	list->fd_listgnl = fd;
	list->i = 0;
	list->next = NULL;
	return (list);
}

static int			ft_errorgnl(const int fd, char **line, t_listgnl **start,
									t_listgnl **list)
{
	char er[0];

	if ((fd < 0) || ((size_t)(BUFF_SIZE + 1) == 0) ||
						read(fd, er, 0) < 0 || !line)
		return (1);
	if (!(*start))
		if (!((*start) = ft_lstgnlnew(fd, NULL)))
			return (1);
	if (!((*list) = ft_lstgnlnew(fd, start)))
		return (1);
	if (!(*line = ft_strnew((size_t)BUFF_SIZE)))
		return (1);
	return (0);
}

static int			ft_buffread(const int fd, char **line, t_listgnl **list,
									long long int *readflag)
{
	char	*linefree;
	char	*linenew;
	size_t	j;
	size_t	len;

	linefree = *line;
	len = ft_strlen(*line);
	if (!(linenew = ft_strnew(len + BUFF_SIZE)))
		return (1);
	*line = ft_strncat(linenew, *line, len);
	free(linefree);
	if ((*list)->i == 0)
	{
		if ((*readflag = read(fd, (*list)->buff, BUFF_SIZE)) <= 0)
			return (1);
		(*list)->buff[(*readflag)] = '\0';
	}
	j = ft_strlen(*line);
	while ((*list)->buff[(*list)->i] != '\n' && (*list)->buff[(*list)->i])
		(*line)[j++] = (*list)->buff[((*list)->i)++];
	return (0);
}

static int			ft_freegnl(t_listgnl **list, t_listgnl **start,
							long long int *rf, char **line)
{
	t_listgnl	*list1;
	size_t		i;

	i = (*list)->i;
	if ((*rf) == 0)
	{
		list1 = (*start);
		if ((*start) == (*list))
		{
			(*start) = (*list)->next;
			free(*list);
		}
		else
		{
			while (list1->next != (*list))
				list1 = list1->next;
			list1->next = (*list)->next;
			free((*list));
		}
	}
	if ((*rf) == 0)
		return ((i != 0) + (i == 0 && ft_strlen(*line) != 0));
	return (-1);
}

int					get_next_line(const int fd, char **line)
{
	static t_listgnl	*start;
	t_listgnl			*list;
	long long int		rf;

	list = NULL;
	rf = -1;
	if (ft_errorgnl(fd, line, &start, &list))
		return (-1);
	while (1)
	{
		if (ft_buffread(fd, line, &list, &rf))
			return (ft_freegnl(&list, &start, &rf, line));
		if (list->buff[list->i] == '\0')
			list->i = 0;
		else if (list->buff[list->i] == '\n')
		{
			(list->i)++;
			break ;
		}
	}
	if (start && !fd)
		ft_freegnl(&list, &start, &rf, line);
	return (1);
}
