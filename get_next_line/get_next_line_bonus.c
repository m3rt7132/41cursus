/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:37:00 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/29 20:41:18 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*freeall(void *area1, void *area2, void *area3)
{
	if (area1)
		free(area1);
	if (area2)
		free(area2);
	if (area3)
		free(area3);
	return ((void *)0);
}
// Bu fonksiyon, satırın geri kalanını (bir sonraki çağrı için) saklar.
// Önceki buffer'ı serbest bırakır ve kalanı içeren yeni bir string döndürür.

char	*save_rest(char *buf)
{
	int		i;
	char	*rest;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (freeall(buf, NULL, NULL));
	rest = ft_strdup(buf + i + (buf[i] == '\n'));
	freeall(buf, NULL, NULL);
	return (rest);
}
// Bu fonksiyon, buffer'dan geçerli satırı ('\n' dahil) çıkarır.

char	*extract_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf || !buf[0])
		return ((void *)0);
	while (buf[i] && buf[i] != '\n')
		i++;
	i += (buf[i] == '\n');
	line = ft_substr(buf, 0, i);
	return (line);
}

// Bu fonksiyon, fd'den '\n' bulana kadar veya dosya sonuna kadar okur.
// Hata durumunda (read < 0) buffer'ı temizler ve NULL döndürür.

char	*read_line(int fd, char *buf)
{
	char	*tmp;
	ssize_t	r;

	tmp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return ((void *)0);
	if (!buf)
		buf = ft_strdup("");
	if (!buf)
		return ((void *)0);
	while (!ft_strchr(buf, '\n'))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r == -1)
			return (freeall(buf, tmp, NULL));
		if (r <= 0)
			break ;
		tmp[r] = 0;
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (freeall(buf, tmp, NULL));
	}
	freeall(tmp, NULL, NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*bufs[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return ((void *)0);
	bufs[fd] = read_line(fd, bufs[fd]);
	if (!bufs[fd])
		return ((void *)0);
	line = extract_line(bufs[fd]);
	bufs[fd] = save_rest(bufs[fd]);
	return (line);
}
