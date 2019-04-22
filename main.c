/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihahn <ihahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:44:18 by ihahn             #+#    #+#             */
/*   Updated: 2019/04/17 14:25:07 by ihahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
    int fd;
    int fd2;
    char *line;

    line = NULL;
    fd = open("./123", O_RDONLY);
    fd2 = open("./1234", O_RDONLY);
    printf("GNL return (%d)\n", get_next_line(fd, &line));
    printf("NextLine 1 - %s\n", line);
    printf("GNL return (%d)\n", get_next_line(fd2, &line));
    printf("NextLine 1 - %s\n", line);
    printf("GNL return (%d)\n", get_next_line(fd, &line));
    printf("NextLine 2 - %s\n", line);
    printf("GNL return (%d)\n", get_next_line(fd2, &line));
    printf("NextLine 2 - %s\n", line);
    printf("GNL return (%d)\n", get_next_line(fd, &line));
    printf("NextLine 3 - %s\n", line);


    printf("GNL return (%d)\n", get_next_line(fd2, &line));
    printf("NextLine 3 - %s\n", line);
    close(fd);
    return (0);
}
