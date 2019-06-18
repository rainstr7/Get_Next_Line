/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:37:12 by ihahn             #+#    #+#             */
/*   Updated: 2019/04/16 18:12:29 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	readlinewidth(char *buff)
{
	size_t		nbread;

	nbread = 0;
	while (buff[nbread] != '\n' && buff[nbread] != '\0')
		nbread++;
	return (nbread);
}

static void		ft_strcopyclean(char *s1, const char *s2)
{
	int			i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	ft_bzero((void *)(&s1[i]), BUFF_SIZE - i);
}

static int		ft_offline(char **line, char *buff, size_t linewidth)
{
	if (buff[linewidth] == '\n' || (buff[0] == '\0' && *line[0] != '\0'))
	{
		if (buff[linewidth] == '\n')
			ft_strcopyclean(buff, &(buff[linewidth + 1]));
		return (1);
	}
	return (0);
}

static char		*ft_strnjoin(char **line, const char *buff, size_t linewidth)
{
	size_t		len;
	char		*newline;
	char		*tmpline;

	if (line == NULL || buff == NULL)
		return (NULL);
	tmpline = *line;
	len = ft_strlen(tmpline);
	if (!(newline = ft_strnew(len + linewidth + 1)))
		return (NULL);
	ft_memcpy(newline, tmpline, len);
	ft_memcpy(newline + len, buff, linewidth);
	free(tmpline);
	return (newline);
}

int				get_next_line(const int fd, char **line)
{
	size_t		linewidth;
	int			nbread;
	static char	buff[OPEN_MAX][BUFF_SIZE + 1];

	nbread = 1;
	if (fd < 0 || !line || fd > OPEN_MAX)
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	while (nbread > 0)
	{
		if (buff[fd][0] == '\0')
			if ((nbread = read(fd, &buff[fd], BUFF_SIZE)) < 0)
				return (nbread);
		linewidth = readlinewidth(buff[fd]);
		*line = ft_strnjoin(line, buff[fd], linewidth);
		if (ft_offline(line, buff[fd], linewidth))
			return (1);
		ft_strclr((char *)&buff[fd]);
	}
	return (0);
}
