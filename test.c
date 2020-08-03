#include <minirt.h>
#include <unistd.h>
#include <sys/errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

int main (int ac, char **av)
{
	int fd;
	char *str;
	if (ac == 1)
		return 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		printf("%s\n", str);
		free(str);
	}
	close(fd);
	return 0;
}
