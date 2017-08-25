/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:49:45 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:49:47 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_save(char *buf, int ret, char **save)
{
	char	*tmp;

	buf[ret] = '\0';
	tmp = *save;
	*save = ft_strjoin(tmp, buf);
	free(tmp);
}

int		ft_notfound(char **line, char **save)
{
	*line = *save;
	*save = NULL;
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*save = NULL;
	char		*stock;
	char		*tmp;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!save)
		save = ft_strnew(1);
	ret = 0;
	while (!(stock = ft_strchr(save, '\n'))
			&& ((ret = read(fd, buf, BUFF_SIZE)) > 0))
		ft_save(buf, ret, &save);
	if (ret < 0)
		return (-1);
	if (ret == 0 && !stock)
		return (ft_notfound(line, &save));
	*line = ft_strsub(save, 0, stock - save);
	tmp = save;
	save = ft_strdup(stock + 1);
	free(tmp);
	return (1);
}
